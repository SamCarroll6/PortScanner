#include "hold.h" 

int main(int argc, char* argv[])
{
//     struct hostent *host; 
//     char *hold; 
//     host = gethostbyname(argv[1]);
//     strcpy(hold , (char*)host->h_addr);
//     printf("%s\n", hold);

    struct hostent *host;
	int err, i , sock ,start , end;
	char hostname[100];
	struct sockaddr_in sa;

	//Initialise the sockaddr_in structure
	strncpy((char*)&sa , "" , sizeof sa);
	sa.sin_family = AF_INET;
	
	printf("Doing inet_addr...");
	printf("%d\n", inet_pton(AF_INET, argv[1], sa.sin_addr.s_addr));
	printf("Done\n");
}