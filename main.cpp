#include "socket.h"
#include <arpa/inet.h>
#include <cstdio>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

const int SOCKET_ERROR_CODE = -1;
const int PORT = 3000;

int main() {
  struct sockaddr_in sockAddress = {
      .sin_family = AF_INET,
      .sin_port = PORT,
  };

  inet_aton("127.0.0.1", &sockAddress.sin_addr);

  int fd = createSocket();

  int bindValue = bindSocket(fd, sockAddress);

  if (bindValue == SOCKET_ERROR_CODE) {
    perror("Error binding address to socket");
    return -1;
  }

  int listenSocketValue = listenSocket(fd, 10);

  if (listenSocketValue == SOCKET_ERROR_CODE) {
    perror("Error trying to listen on port: 3000");
    return -1;
  }

  while (true) {
    int acceptSocketValue = acceptSocket(fd, sockAddress);

    std::cout << acceptSocketValue << "\n";

    if (acceptSocketValue == SOCKET_ERROR_CODE) {
      perror("Error accepting socket connection");
      return -1;
    }

    char buffer[10000];

    int receiveMessageValue = receiveMessage(acceptSocketValue, &buffer, MSG_PEEK);

    if (receiveMessageValue == SOCKET_ERROR_CODE) {
      std::cout << "Error trying to read socket data";
      return -1;
    }

    std::cout << buffer << "\n";
  }
}