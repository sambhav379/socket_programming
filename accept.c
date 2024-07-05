#include <sys/types.h>
#include <sys/socket.h>
#include"header.h"


int accept_my(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
	int new_fd;
	new_fd = accept(sockfd,addr,addrlen);
	if (new_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
 	   }
	return new_fd;
}
