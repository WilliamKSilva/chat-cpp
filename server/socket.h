#include <netinet/in.h>
#include "messages.h"

int createSocket();

int bindSocket(int fileDescriptor, sockaddr_in& sockAddress);

int connectSocket(int fileDescriptor, sockaddr_in& sockAddress);

int listenSocket(int socket, int backlog);

int acceptSocket(int socket, sockaddr_in& sockAddress);

int receiveMessage(int socket, void* buffer, int flags);

int closeSocketConnection(int socket, int how);

void acceptAndReadSocket(int fd, sockaddr_in& sockAddress, Messages& messages);