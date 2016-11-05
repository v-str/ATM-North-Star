#include "account_messenger.h"

#include <iostream>

void AccountMessenger::DisplayInfoLine(const std::string &info_title,
                                       const std::stringstream &stream) const {
  std::cout << "\n\t# " << info_title << stream.str() << "\n\t";
  DisplayStrip();
}

void AccountMessenger::DisplayStrip() const {
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}
