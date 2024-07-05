#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include"header.h"

void my_getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res){
	int status;
	if((status = getaddrinfo( node, service, hints, res)) != 0){
     	   perror("getaddrinfo");
      	   exit(EXIT_FAILURE);
	}
	
}
