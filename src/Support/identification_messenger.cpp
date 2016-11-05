#include "identification_messenger.h"

#include <iostream>

void IdentificationMessenger::ShowInitialLoginText() const {
  std::cout << "\n\n\n\t\tLogin: ";
  utility_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void IdentificationMessenger::ShowInitialPasswordText() const {
  std::cout << "\t\tPassword: XXXX\b\b\b\b";
  utility_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
