/**
First attempt at a basic Port Scanner in C.
**/

#include "ps.h" 

int main(int argc, char* argv[])
{

    double time = 0;

    // Only needs one argument, the ipv4 value to scan the ports of. 
    // Without this value it wont know what to scan and thus exits.
    if(argc != 2)
    {
        printf("Invalid syntax: Must include IP Address to scan\n");
        printf("Usage: ./makefile <ipv4 address>\n");
        exit(0);
    }
    // Only if correct number of inputs received. 
    char IPadd[16] = {'\0'};
    strcpy(IPadd, argv[1]);
    printf("%s\n", IPadd);

    time = portscan(IPadd);
    printf("time: %lf milliseconds\n", time);
    return 0;
}


// double portscan(char *IPadd, int p, int rank)
// {
//     // Time structs to check runtime
//     struct timeval t1,t2;
//     double runtime = 0;
//     // sockfd returns the integer value to represent the open socket
//     int sockfd = 0;
//     // Variable will be used to see if a connection is established or not
//     int connectcheck = 0;
//     // Will be used in connect for sockaddr variable
//     struct sockaddr_in sk_addr;
//     int start, end; 
//     if(rank == 0)
//     {
//         start = 1;
//         end = (int)65535/p + (65535 % p);
//     }
//     else
//     {
//         start = ((int)65535/p) * rank + (65535 % p) + 1;
//         end = ((int)65535/p) * (rank + 1) + (65535 % p);
//     }
//     int port = start;
//     gettimeofday(&t1,NULL);
//     for(port; port <= end; port++)
//     {
//         if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
//         {
//             printf("%d\n", port);
//             printf("Error: Socket failed\n");
//             exit(0);
//         }
//         //printf("sockfd = %d\n", sockfd);
//         sk_addr.sin_addr.s_addr = inet_addr(IPadd);
//         sk_addr.sin_family = AF_INET;
//         sk_addr.sin_port = htons(port);
//         connectcheck = connect(sockfd, (struct sockaddr*)&sk_addr, sizeof(sk_addr));

//         //printf("Port = %d\n", ntohs(sk_addr.sin_port));

//         if(connectcheck < 0)
//         {
//             //printf("Port %d is not open\n", port);
//         }
//         else
//         {
//             printf("Port %d is open\n", port);
//         }
//         close(sockfd); 
//     }
//     gettimeofday(&t2,NULL);

//     runtime = (t2.tv_sec-t1.tv_sec)*1000 + (double)(t2.tv_usec-t1.tv_usec)/1000;

//     return runtime;

    
// }