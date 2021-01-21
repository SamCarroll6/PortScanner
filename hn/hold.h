#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <mpi.h>
#include <sys/time.h>
#include <time.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <assert.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>

int portscan(char * printip, int ipv);