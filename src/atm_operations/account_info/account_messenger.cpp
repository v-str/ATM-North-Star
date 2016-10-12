#include "account_messenger.h"

void AccountMessenger::DisplayUserInformation(
    const std::string &info_title,
    const std::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void AccountMessenger::DisplayStrip() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
}
