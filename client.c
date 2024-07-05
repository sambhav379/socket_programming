#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include"header.h"

#define PORT "3490"
//#define SERVER_ADDR "172.26.183.102"

int main(){
	//printf("herer");
	struct addrinfo hints, *servinfo;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	my_getaddrinfo(NULL,PORT, &hints, &servinfo);
	//printf("here1");

	int client_fd;
	// struct addrinfo *p;
	// for(p = servinfo; p != NULL; p = p->ai_next){
	// 	client_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	// 	if(client_fd == -1){
	// 		perror("client: socket");
	// 		continue;
	// 	}

	// 	if(connect(client_fd, p->ai_addr, p->ai_addrlen) == -1){
	// 		close(client_fd);
	// 		perror("client: connect");
	// 		continue;
	// 	}

	// 	break;
	// }

	client_fd = socket_my(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	//printf("here2");
	connect_my(client_fd, servinfo->ai_addr, servinfo->ai_addrlen);
	//printf("here3");

	freeaddrinfo(servinfo);

	// if(p == NULL){
	// 	fprintf(stderr, "client: failed to connect\n");
	// 	return 2;
	// }
	
	while(1){
		char input[1024];
		    if (fgets(input, sizeof(input), stdin) == NULL) {
			perror("fgets");
			return 5;
		    }
		    input[strcspn(input, "\n")] = '\0';

		if(send(client_fd, input, strlen(input), 0) == -1){
			perror("send");
			return 3;
		}
	}
	//printf("Client: Hello msg sent from client!\n");

	// char buffer[1024];
	// if(recv(client_fd, buffer, sizeof(buffer), 0) == -1){
	// 	perror("recv");
	// 	return 4;
	// }

	// printf("Client1: received '%s'\n", buffer);

	// const char *hello1 = "how are you?";
	// send(client_fd, hello1, strlen(hello1), 0);
	// printf("Client: Hello2 msg sent from client!\n");

	// int inp = 5;
	// for(int j = 0; j < inp; ++j){
	// 	printf("\nEnter msg: ");
	// 	char input_msg[100];
	// 	scanf("%99s", input_msg);

	// 	send(client_fd, input_msg, strlen(input_msg), 0);
	// 	printf("\nClient: Input msg sent from client!\n");
	// }

	close(client_fd);

	return 0;
}
