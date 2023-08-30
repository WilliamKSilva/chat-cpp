#include "messages.h"
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

const int SOCKET_ERROR_CODE = -1;

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

int closeSocketConnection(int socket, int how) {
  return shutdown(socket, how);
}

void acceptAndReadSocket(int fd, sockaddr_in& sockAddress, Messages& messages) {
  char buffer[10000];

  int socket = acceptSocket(fd, sockAddress);
  
  int bytes = receiveMessage(socket, &buffer, MSG_PEEK);

  if (bytes == -1) {
    perror("Error trying to read incoming data");
    return;
  }

  messages.newMessage(buffer);

  // int closeConnectionReturn = closeSocketConnection(socket, SHUT_RDWR);

  // if (closeConnectionReturn == SOCKET_ERROR_CODE) {
    // perror("Error trying to close socket connection");
    // return;
  // }

  // std::cout << "Connection closed!" << "\n";
}

int sendMessageSocket(int fd, void* buffer) {
  return send(fd, buffer, sizeof(buffer), MSG_EOR);
}