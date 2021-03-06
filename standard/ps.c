#include "ps.h"

double portscan(char *IPadd)
{
    // Time structs to check runtime
    struct timeval t1,t2;
    double runtime = 0;
    // sockfd returns the integer value to represent the open socket
    int sockfd = 0;
    // Variable will be used to see if a connection is established or not
    int connectcheck = 0;
    // Will be used in connect for sockaddr variable
    struct sockaddr_in sk_addr;

    int port = 1;
    gettimeofday(&t1,NULL);
    for(port; port <= 65535; port++)
    {
        //printf("In\n");
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        {
            printf("%d\n", port);
            printf("Error: Socket failed\n");
            exit(0);
        }
        //printf("sockfd = %d\n", sockfd);
        sk_addr.sin_addr.s_addr = inet_addr(IPadd);
        sk_addr.sin_family = AF_INET;
        sk_addr.sin_port = htons(port);
        //printf("Conn check\n");
        connectcheck = connect(sockfd, (struct sockaddr*)&sk_addr, sizeof(sk_addr));

        //printf("Port = %d\n", ntohs(sk_addr.sin_port));

        if(connectcheck < 0)
        {
            //printf("Port %d is not open\n", port);
        }
        else
        {
            printf("Port %d is open\n", port);
        }
        close(sockfd); 
    }
    gettimeofday(&t2,NULL);

    runtime = (t2.tv_sec-t1.tv_sec)*1000 + (double)(t2.tv_usec-t1.tv_usec)/1000;

    return runtime;

    
}