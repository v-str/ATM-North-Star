#include "account_messenger.h"

void AccountMessenger::DisplayUserInformation(const std::string &info_title,
                                              const std::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  DisplayStripWithDelay();
}

void AccountMessenger::DisplayInfoLine(const std::__cxx11::string info_title,
                                       const std::__cxx11::string value) const {
  cout << "\n\t# " << info_title << value << "\n\t";
  DisplayStripWithDelay();
}

void AccountMessenger::DisplayStripWithDelay() const {
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}
