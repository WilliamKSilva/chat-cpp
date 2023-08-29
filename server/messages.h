#include <string>
#include <iostream>

class Messages {
  private:
    std::string queue[50];
    int size = 0;

  public:
    int getSize();

    void newMessage(std::string message);

    void stdOutMessages();
};