#include "../socket.h"
#include <arpa/inet.h>

const int SOCKET_ERROR_CODE = -1;
const int PORT = 3000;

int main() {
  // int fd = createSocket();

  // struct sockaddr_in sockAddress = {
      // .sin_family = AF_INET,
      // .sin_port = PORT,
  // };

  // inet_aton("127.0.0.1", &sockAddress.sin_addr);

  // int socketConnection = connectSocket(fd, sockAddress);

  // if (socketConnection == SOCKET_ERROR_CODE) {
    // return -1;
  // }

  char userInput;

  while(true) {
    std::cin >> userInput;

    std::cout << userInput;
  }
}