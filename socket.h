#include <netinet/in.h>

int createSocket();

int bindSocket(int fileDescriptor, sockaddr_in& sockAddress);

int connectSocket(int fileDescriptor, sockaddr_in& sockAddress);

int listenSocket(int socket, int backlog);

int acceptSocket(int socket, sockaddr_in& sockAddress);

int receiveMessage(int socket, void* buffer, int flags);