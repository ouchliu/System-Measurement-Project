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
    char* ip_address;
    if (argc == 2) {
	ip_address = argv[1];
    } else {
	printf("Please enter server ip address\n");
	return 1;
    }

    struct sockaddr_in server;
    server.sin_addr.s_addr =inet_addr(ip_address);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8888 );

    // Create socket
    int sock;
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
        printf("Error: fails to create socket");

    //Connect socket so we can send data.
    connect(sock , (struct sockaddr *)&server , sizeof(server));
    
    //Compute rtt
    tick ts, te;
    char c = 'a';
    int j;
    for (j = 0; j < 100; ++j) {
        ts = gettick();
        send(sock, &c, sizeof(c), 0);
        recv(sock, &c, sizeof(c), 0);
        te = gettick();
        printf ("%llu\n", te - ts);
    }
    return 0;
}
