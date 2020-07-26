/**
First attempt at a basic Port Scanner in C.
**/

#include "ps.h" 

int main(int argc, char* argv[])
{
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

    portscan(IPadd);

    return 0;
}