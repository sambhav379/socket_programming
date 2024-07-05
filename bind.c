#include <sys/types.h>
#include <sys/socket.h>
#include"header.h"

void bind_my(int sockfd, struct sockaddr *my_addr, int addrlen){
	int bind_return;
	bind_return = bind(sockfd,my_addr,addrlen);
	if(bind_return == -1){
		perror("bind");
        	exit(EXIT_FAILURE);
	}

}
