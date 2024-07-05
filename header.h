#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

void my_getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
int socket_my(int domain, int type, int protocol);
void bind_my(int sockfd, struct sockaddr *my_addr, int addrlen);
void connect_my(int sockfd, struct sockaddr *serv_addr, int addrlen);
int accept_my(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
