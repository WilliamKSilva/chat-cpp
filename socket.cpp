#include "socket.h"
#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

int createSocket() { return socket(PF_INET, SOCK_STREAM, 1); }

int bindSocket(int fileDescriptor, sockaddr_in& sockAddress) {
  inet_aton("127.0.0.1", &sockAddress.sin_addr);

  return bind(fileDescriptor, (struct sockaddr *)&sockAddress,
              sizeof(sockAddress));
}

int connectSocket(int socket, sockaddr_in& sockAddress) {
  return connect(socket, (struct sockaddr *)&sockAddress, sizeof(sockAddress));
}