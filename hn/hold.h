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

// These define checking what type of value was passed.
#define uk 0
#define ip 1
#define hn 2

// These will define the type of ip address returned. 
#define v4 1
#define v6 2

// Resulting IP address, should be equal to either v4 or v6 after this is checked in main. 
int resip;