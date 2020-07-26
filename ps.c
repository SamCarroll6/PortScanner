#include "ps.h"

int portscan(char *IPadd)
{
    // sockfd returns the integer value to represent the open socket
    int sockfd = 0;
    // Variable will be used to see if a connection is established or not
    int connectcheck = 0;
    // Will be used in connect for sockaddr variable
    struct sockaddr_in sk_addr;

    int port = 1;
    for(port; port <= 65535; port++)
    {
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
    return 0;

    
}