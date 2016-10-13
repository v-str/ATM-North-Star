#include "information_screen.h"

void InformationScreen::DisplayUserInformation(const std::string &info_title,
                                               const std::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void InformationScreen::DisplayStrip() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
}

void InformationScreen::DisplayLogin(const std::string &login) const {
  DisplayUserInformation(account_messenger_.LoginText(), login);
}

