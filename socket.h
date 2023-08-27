#include <netinet/in.h>

int createSocket();

int bindSocket(int fileDescriptor, sockaddr_in& sockAddress);

int connectSocket(int fileDescriptor, sockaddr_in& sockAddress);