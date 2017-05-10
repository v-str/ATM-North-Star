#include "greeting_messenger.h"

#include <iostream>

void GreetingMessenger::ShowGreetingMessage() { DrawStrip('#', strip_length_); }

void GreetingMessenger::DrawStrip(const char symbol, int strip_length) {
  for (int i = 0; i < strip_length; ++i) {
    std::cout << symbol;
  }
  std::cout << std::endl;
}
