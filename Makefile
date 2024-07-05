CC = gcc
CFLAGS = -g

server: server.o socket.o bind.o getaddrinfo.o accept.o
	$(CC) server.o socket.o bind.o getaddrinfo.o accept.o -o server
	
client: client.o socket.o connect.o getaddrinfo.o
	$(CC) client.o socket.o connect.o getaddrinfo.o -o client 	

server.o: server.c header.h
	$(CC) -c server.c	

client.o: client.c header.h
	$(CC) -c client.c

socket.o: socket.c header.h
	$(CC) -c socket.c

bind.o: bind.c header.h
	$(CC) -c bind.c

connect.o: connect.c header.h
	$(CC) -c connect.c		

accept.o: accept.c header.h
	$(CC) -c accept.c	
	

clean: 
	rm -f *.o server client
