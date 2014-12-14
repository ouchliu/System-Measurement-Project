#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <linux/tcp.h>
#include <linux/socket.h>

typedef unsigned long long tick;
static __inline__ tick gettick (void) {
    unsigned a, d;
    __asm__ __volatile__("rdtsc": "=a" (a), "=d" (d) );
    return (((tick)a) | (((tick)d) << 32));
}

int main(int argc , char *argv[])
{        
    struct sockaddr_in server;
    server.sin_addr.s_addr =inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );
    int i = 0;
    tick ts, te; /* tick start, tick end */
    int sock;
    char message[1000] , server_reply[2000];
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");
    ts = gettick ();
    connect(sock , (struct sockaddr *)&server , sizeof(server));
    te = gettick ();
    printf ("setup = %llu\n", te - ts);
    char c;
    for (int j = 0; j < 100; ++j) {
        ts = gettick();
        send(sock, &c, sizeof(c), 0);
        recv(sock, &c, sizeof(c), 0);
        te = gettick();
        printf ("%llu\n", te - ts);
    }
    i++;
    return 0;
}
