#include "identification_messenger.h"

#include <iostream>

void IdentificationMessenger::ShowInitialLoginText() const {
  std::cout << "\n\n\n\t\tLogin: ";
  text_editor_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  text_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  std::cout << "\t\tPassword: XXXX\b\b\b\b";
  text_editor_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  text_editor_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
