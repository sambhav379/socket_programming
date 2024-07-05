#include <sys/types.h>
#include <sys/socket.h>
#include"header.h"

int socket_my(int domain, int type, int protocol){
	int sockfd = socket(domain,type,protocol);
	if(sockfd == -1){
		perror("socket");
        	exit(EXIT_FAILURE);
	}
	return sockfd;

}

