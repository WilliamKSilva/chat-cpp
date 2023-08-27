#include "socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h> 

int createSocket() { return socket(PF_INET, SOCK_STREAM, 0); }

int bindSocket(int fileDescriptor, sockaddr_in& sockAddress) {
  return bind(fileDescriptor, (struct sockaddr *)&sockAddress,
              sizeof(sockAddress));
}

int connectSocket(int socket, sockaddr_in& sockAddress) {
  return connect(socket, (struct sockaddr *)&sockAddress, sizeof(sockAddress));
}

int listenSocket(int socket, int backlog) {
  return listen(socket, 10);
}

int acceptSocket(int socket, sockaddr_in& sockAddress) {
  socklen_t addr_size = sizeof(sockAddress);
  return accept(socket, (struct sockaddr *)&sockAddress, &addr_size);
}

int receiveMessage(int socket, void* buffer, int flags) {
  return recv(socket, buffer, sizeof(char) * 10000, flags);
}