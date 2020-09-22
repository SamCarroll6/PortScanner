#include "hold.h" 

int main(int argc, char* argv[])
{
//     struct hostent *host; 
//     char *hold; 
//     host = gethostbyname(argv[1]);
//     strcpy(hold , (char*)host->h_addr);
//     printf("%s\n", hold);
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

	if(res->ai_family == AF_INET)
	{
		resip = v4;
		printf("ipv4\n");
	}
	else if(res->ai_family == AF_INET6)
	{
		resip = v6;
		printf("ipv6\n");
	}
	else
	{
		printf("Error: Invalid entry\n");
		exit(1);
	}
	
	
	/*
	 * Below it will convert the sock_addr returned by getaddrinfo
	 * back into an ip address string, this lets me see that it is
	 * correctly handling the hostname resolution by ensuring that an
	 * ip address is being returned. 
	 */
	if(resip == v4)
	{
		ipaddr = (struct sockaddr_in*)res->ai_addr;
		printip = inet_ntoa(ipaddr->sin_addr);
		printf("%s\n", printip);
	}
	else if(resip == v6)
	{
		ipaddr6 = (struct sockaddr_in6*)res->ai_addr;
		inet_ntop(AF_INET6, &ipaddr6->sin6_addr, printip, 128);
		printf("%s\n", printip);
	}
}