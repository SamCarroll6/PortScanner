/**
First attempt at a basic Port Scanner in C.
**/

#include "ps.h" 

int main(int argc, char* argv[])
{

    double time = 0;
    int p, rank; 

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&p);

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
    printf("Rank=%d of %d %s\n", rank, p, IPadd);
    time = portscan(IPadd, p, rank);
    printf("Rank %d time: %lf milliseconds\n", rank, time);
    MPI_Finalize();
}
