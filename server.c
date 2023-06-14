// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024


int findlength(char* str)
{
    int count=0;
    for(int i=0;str[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
char* reversestring(char* str){
        char ch;
        int len=findlength(str);
        for(int i=0;i<len/2;i++){
                ch=str[i];
                str[i]=str[len-1-i];
                str[len-1-i]=ch;
        }
        for(int i=0;i<len;i++){
                printf("%c",str[i]);
        }
        printf("\n");
        return str;
}


// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	int check=0;
	while(1)
	{
		int len, n;
		char buffer[MAXLINE]="";
		char hello[200] = "";
		len = sizeof(cliaddr); //len is value/resuslt

		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, ( struct sockaddr *) &cliaddr,
					&len);
		buffer[n] = '\0';
		check=strcmp(buffer,"bye");
		printf("Client Reverse Message :  ");
		reversestring(buffer);
		
		if(check==0)
		return 0;
		printf("Enter Server Message: \n");
		fgets(hello, 100, stdin);
		sendto(sockfd, (const char *)hello, strlen(hello),
			0, (const struct sockaddr *) &cliaddr,
				len);
		check=strcmp(hello,"bye");
		if(check==0)
		{
			
			return 0;
		}
	}
	
	return 0;
}
