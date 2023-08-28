#include <arpa/inet.h>
#include <cstdio>
#include <functional>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <thread>

#include "socket.h"

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

  Messages messages;

  while (true) {
    // Approach de idiota, tenho que fazer uma thread pool pra usar
    // os recursos direito
    // std::thread t(acceptAndReadSocket, fd, std::ref(sockAddress));
    std::cout << messages.getSize() << "\n";

    messages.stdOutMessages();
    
    acceptAndReadSocket(fd, sockAddress, messages);

    // t.join();
  }
}