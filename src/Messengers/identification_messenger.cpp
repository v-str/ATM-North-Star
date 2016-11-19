#include "identification_messenger.h"

#include <iostream>

void IdentificationMessenger::ShowInitialLoginText() const {
  std::cout << "\n\n\n\t\tLogin: ";
  console_editor_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  console_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  std::cout << "\t\tPassword: XXXX\b\b\b\b";
  console_editor_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  console_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
