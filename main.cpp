#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include "socket.h"

int main() {
  struct sockaddr_in sockAddress = {
      .sin_family = AF_INET,
      .sin_port = 3000,
  };

  int fd = createSocket();
  int bindValue = bindSocket(fd, sockAddress);

  if (bindValue == -1) {
    std::cout << "Error binding address to socket"; 
    return -1;
  }

  int connectionValue = connectSocket(fd, sockAddress);

  if (connectionValue == -1) {
    std::cout << "Error on socket connection";
    return -1;
  }
}