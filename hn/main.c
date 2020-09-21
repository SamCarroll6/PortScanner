#include "hold.h" 

int main(int argc, char* argv[])
{
//     struct hostent *host; 
//     char *hold; 
//     host = gethostbyname(argv[1]);
//     strcpy(hold , (char*)host->h_addr);
//     printf("%s\n", hold);
	struct addrinfo VC, *res;
	int ret, ipcheck;
	
	assert(argc > 1);
	/* 
	 * Check to resolve if ip address provided or if hostname was provided.
	 * Do this by checking the first byte of the provided string
 	 */
	if(argv[1][0] > 48 && argv[1][0] < 58)
	{
		ipcheck = ip;


		memset(&VC, '\0', sizeof VC);
		VC.ai_family = PF_UNSPEC;
		VC.ai_flags = AI_NUMERICHOST;

		ret = getaddrinfo(argv[1], NULL, &VC, &res);
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
			printf("Error: Ip address neither ipv4 or ipv6\n");
			exit(1);
		}
	
	}	 
	else if((argv[1][0] >= 65 && argv[1][0] <= 90) || (argv[1][0] >= 97 && argv[1][0] <= 122)) 
	{
		ipcheck = hn;
	}
	else
	{
		ipcheck = uk;
		printf("Error: Must include valid hostname or ip address\n");
		exit(1);
	}

	switch(ipcheck)
	{
		case ip: printf("Value is an ip address\n");
				 break;
		case hn: printf("Value is a hostname\n");
				 break;
	}



	// struct hostent *host;
	// int err, i , sock ,start , end;
	// char hostname[100];
	// struct sockaddr_in sa;

	// //Initialise the sockaddr_in structure
	// strncpy((char*)&sa , "" , sizeof sa);
	// sa.sin_family = AF_INET;
	
	// printf("Doing inet_addr...");
	// printf("%d\n", inet_pton(AF_INET, argv[1], sa.sin_addr.s_addr));
	// printf("Done\n");
}