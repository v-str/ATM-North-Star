#include "greeting_messenger.h"

#include <iostream>
#include <sstream>

void GreetingMessenger::ShowGreetingMessage() {
  DrawStrip('#', strip_length_);
  AddString('#', "ATM system \"North star\"");
  AddString('#', " ");
  AddString('#', "Please, choose the appropriate app mode");
  AddString('#', " ");
  AddString('#', "1. Console mode");
  AddString('#', "2. Graphical mode");
  AddString('#', "Enter: ");
  AddString('#', " ");
  DrawStrip('#', strip_length_);
}

void GreetingMessenger::DrawStrip(const char strip_symbol, int strip_length) {
  for (int i = 0; i < strip_length; ++i) {
    std::cout << strip_symbol;
  }
  std::cout << std::endl;
}

void GreetingMessenger::AddString(const char strip_symbol,
                                  const std::string& string) {
  std::stringstream stream;
  stream << strip_symbol << " " << string;

  std::string new_string = stream.str();
  int spaces = strip_length_ - new_string.size() - 1;
  for (int i = 0; i < spaces; ++i) {
    new_string.push_back(' ');
  }
  new_string.push_back(strip_symbol);
  std::cout << new_string << std::endl;
}
