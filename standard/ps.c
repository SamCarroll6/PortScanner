#include "ps.h"

double portscan(char *IPadd)
{
    // Time structs to check runtime
    struct timeval t1,t2,blocktime;
    double runtime = 0;
    fd_set rfds;
    // sockfd returns the integer value to represent the open socket
    int sockfd = 0;
    // Variable will be used to see if a connection is established or not
    int connectcheck = 0, val;
    // Will be used in connect for sockaddr variable
    struct sockaddr_in sk_addr;
    int cc = 0;
    blocktime.tv_sec = 1;
    blocktime.tv_usec = 0;

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


        val = fcntl (sockfd, F_GETFL, 0); 
        fcntl (sockfd, F_SETFL, val | O_NONBLOCK);

        FD_ZERO(&rfds);
        FD_SET(sockfd, &rfds);

        //printf("sockfd = %d\n", sockfd);
        sk_addr.sin_addr.s_addr = inet_addr(IPadd);
        sk_addr.sin_family = AF_INET;
        sk_addr.sin_port = htons(port);
        //printf("Conn check\n");
        connectcheck = connect(sockfd, (struct sockaddr*)&sk_addr, sizeof(sk_addr));
        
        
        cc = select(sockfd, &rfds, NULL, NULL, &blocktime);
        printf("%d, %d\n", cc, port);

        //printf("Port = %d\n", ntohs(sk_addr.sin_port));

        if(connectcheck < 0)
        {
            printf("Port %d is not open\n", port);
        }
        else
        {
            printf("Port %d is open\n", port);
        }
        FD_CLR(sockfd, &rfds);
        close(sockfd); 
    }
    gettimeofday(&t2,NULL);

    runtime = (t2.tv_sec-t1.tv_sec)*1000 + (double)(t2.tv_usec-t1.tv_usec)/1000;

    return runtime;

    
}