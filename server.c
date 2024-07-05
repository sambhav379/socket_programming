#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include"header.h"

#define PORT "3490"

int main()
{
	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo;
	struct sockaddr_storage client_addr;
	socklen_t addr_size;
	
	const char *hello = "Hello from server";

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	// printf("here");

	my_getaddrinfo( NULL, PORT, &hints, &servinfo);


	// struct addrinfo *p;
	int server_fd;
	// for(p = servinfo; p != NULL; p = p->ai_next){
	// 	server_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
	// 	if(server_fd == -1){
	// 		perror("server: socket");
	// 		continue;
	// 	}

	// 	if(bind(server_fd, p->ai_addr, p->ai_addrlen) == -1){
	// 		close(server_fd);
	// 		perror("server: bind");
	// 		continue;
	// 	}

	// 	break;
	// }

	server_fd = socket_my(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
	
	bind_my(server_fd, servinfo->ai_addr, servinfo->ai_addrlen);

	freeaddrinfo(servinfo);

	// if(p == NULL){
	// 	fprintf(stderr, "server: failed to bind\n");
	// 	return 2;
	// }
	while(1){
	if(listen(server_fd, 10) == -1){
		perror("listen");
		return 3;
	}

	printf("Server: waiting for connections...\n");

	addr_size = sizeof(client_addr);
	int client_fd = accept_my(server_fd, (struct sockaddr *)&client_addr, &addr_size);
	/*if(client_fd == -1){
		perror("accept");
		return 4;
	}*/
	char buffer[1024];
	inet_ntop(client_addr.ss_family,&(((struct sockaddr_in *)&client_addr)->sin_addr), buffer, sizeof(buffer));

	printf("Server: got connection from %s\n", buffer);
	
	
	while(1){
	char buffer_msg[1024];
	int bytes_received = recv(client_fd, buffer_msg, sizeof(buffer_msg), 0);
	if (bytes_received==0){
		printf("Client disconnected\n");
		break;
		}
	printf("REceived %d bytes\n",bytes_received);
	if(bytes_received == -1){
		perror("recv");
		return 5;
	}

	printf("Server: received '%s'\n", buffer_msg);
	memset(buffer_msg,0,sizeof(buffer_msg));
	}
	//if(send(client_fd, "hello", strlen(hello), 0) == -1){
	//	perror("send");
	//	return 6;
	//}
	}
	//close(client_fd);
	close(server_fd);


	return 0;
}


