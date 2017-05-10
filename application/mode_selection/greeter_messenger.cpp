#include "greeter_messenger.h"

#include <iostream>

void GreeterMessenger::ShowGreetingMessage() { DrawStrip('#', 50); }

void GreeterMessenger::DrawStrip(const char symbol, int length_of_strip) {
  for (int i = 0; i < length_of_strip; ++i) {
    std::cout << symbol;
  }
  std::cout << std::endl;
}
