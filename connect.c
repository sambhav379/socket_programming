#include <sys/types.h>
#include <sys/socket.h>
#include"header.h"

void connect_my(int sockfd, struct sockaddr *serv_addr, int addrlen){
	int connect_return;
	connect_return = connect(sockfd,serv_addr,addrlen);
	if(connect_return== -1){
		perror("connect");
        	exit(EXIT_FAILURE);
	}
	
}
