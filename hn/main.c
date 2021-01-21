/*
 * The start of my current project, this resolves a hostname or ip address
 * provided by the user and returns the sockaddr_in with the relevant ip address.
 * My further plan is to use the ip that is retrieved and run a port scan on that ip.
 * I also plan to look at incorporating threading into this project once the port scan
 * is active as a way to boost the overall performance. For this I plan to use MPI for my 
 * implementation. You can see an early outline of this idea on my github at:
 * 			https://github.com/SamCarroll6/PortScanner/tree/master/mpi
 */

#include "hold.h" 


int main(int argc, char* argv[])
{
	struct addrinfo VC, *res;
	struct sockaddr_in *ipaddr;
	struct sockaddr_in6 *ipaddr6;
	char *printip;
	int ret, ipcheck;

	assert(argc > 1);

	memset(&VC, '\0', sizeof VC);
	VC.ai_family = PF_UNSPEC;
	VC.ai_socktype = SOCK_STREAM;

	ret = getaddrinfo(argv[1], "http", &VC, &res);
	if(ret)
	{
		printf("Error: Must include valid hostname or ip address\n");
		exit(1);
	}
	
	
	/*
	 * Below it will convert the sock_addr returned by getaddrinfo
	 * back into an ip address string, this lets me see that it is
	 * correctly handling the hostname resolution by ensuring that an
	 * ip address is being returned. 
	 */
	if(res->ai_family == AF_INET)
	{
		ipaddr = (struct sockaddr_in*)res->ai_addr;
		printip = inet_ntoa(ipaddr->sin_addr);
		printf("ipv4\n");
		printf("%s\n", printip);
	}
	else if(res->ai_family == AF_INET6)
	{
		ipaddr6 = (struct sockaddr_in6*)res->ai_addr;
		inet_ntop(AF_INET6, &ipaddr6->sin6_addr, printip, 128);
		printf("ipv6\n");
		printf("%s\n", printip);
	}
	else
	{
		printf("Error: Invalid entry\n");
		exit(1);
	}
	portscan(printip, res->ai_family);
}

int portscan(char * printip, int ipv)
{
	int fd = 0;

	if(ipv == AF_INET)
	{
		fd = socket(PF_INET, SOCK_STREAM, 0);
	}
	else if(ipv == AF_INET6)
	{
		fd = socket(PF_INET6, SOCK_STREAM, 0);
	}
	else
	{
		// Handled this in the main function technically
		// but it felt incomplete without an else.
		printf("Unable to open socket: Invalid IP Address\n");
		exit(1);
	}
	return 0;
}