# PortScanner
Basic port scanner written in C.

## To Run:

### Option 1 Standard: 
Go into the **Standard** directory

Simply execute the provided makefile, be sure to include the ipv4 address that you wish for the program to scan. The code will not run without a provided ip address as it will not know what to scan. 

Usage: ./makefile <ip address>

### Option 2 Threaded:
Go into the **MPI** directory

Run the run.sh program provided in the program. You must provide the number of threads you wish to use first followed by the IP address that you want to scan. 

Usage: ./run.sh <number of threads> <ip address>