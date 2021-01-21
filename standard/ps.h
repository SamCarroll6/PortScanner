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
#include <unistd.h>
#include <fcntl.h>

#ifndef PS_H
#define PS_H

double portscan(char *IPadd);

#endif