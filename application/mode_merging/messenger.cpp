#include "messenger.h"

#include <iostream>

void Messenger::ShowGreetingMessage() {
  std::cout << "v.1.0.1\n\n"
               "ATM system \"North Star\"\n\n\n"
               "Choose the interface:\n\n"
               "1.Console \n"
               "2.Graphical \n\n"
               "(\'q\' for quit)\n\n"
               "Enter: ";
}

void Messenger::IncorrectInput() {
  std::cout << "Incorrect input, please re-enter: ";
}
