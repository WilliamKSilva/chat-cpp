#include "messages.h"
#include <string>

int Messages::getSize() { return Messages::size; }

void Messages::newMessage(std::string message) {
  Messages::size = Messages::size + 1;
  Messages::queue[Messages::size - 1] = message;
}

void Messages::stdOutMessages() {
  for (auto message : queue) {
    if (!message.empty()) {
      std::cout << message << "\n";
    }
  }
}