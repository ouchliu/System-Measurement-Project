#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BLOCK_SIZE 1460000
typedef unsigned long long tick;

static __inline__ tick gettick (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtsc": "=a" (a), "=d" (d) );
    return (((tick)a) | (((tick)d) << 32));
}

int main(int argc , char *argv[])
{        
    struct sockaddr_in server;
    
    //Prepare sockaddr_in structure
    server.sin_addr.s_addr =inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
    
    tick ts, te, dur;
    int sock; ssize_t bytes; ssize_t readsize;
    long long i = 1;
    char buf[BLOCK_SIZE];
    
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
        printf("Error: fails to create socket");
    puts("Socket created");
    
    tick tss = gettick();
    ts = gettick();
    connect(sock , (struct sockaddr *)&server , sizeof(server));
    
    
    ssize_t cnt = recv(sock, buf, BLOCK_SIZE, MSG_WAITALL);
    printf ("cnt = %d\n", (int)cnt); // ensure that 1460*1000 
    te = gettick();
    
    dur = te - ts; 
    printf ("setup: %llu\n", dur);
    
    ts = te;
    while ((bytes = recv(sock, buf, BLOCK_SIZE, MSG_WAITALL)) > 0) {
        te = gettick();
        tick dur = te - ts;
        ts = te;
        i++;
        readsize = readsize + bytes;
        printf ("bytes: %llu, timecount: %llu\n", (unsigned long long) bytes, dur);
    }
    tick tee = gettick();
    printf ("Total bytes received: %llu, time: %llu\n", (unsigned long long)readsize + cnt, tee - tss);
    close(sock);
    return 0;
}
