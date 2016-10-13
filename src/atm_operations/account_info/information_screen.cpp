#include "information_screen.h"

void InformationScreen::DisplayUserInformation(
    const std::__cxx11::string &info_title,
    const std::__cxx11::string &value) const {
  cout << "\n\t# " << info_title << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void InformationScreen::DisplayUserInformation(
    const std::__cxx11::string &info_title, const int &value) const {
  cout << "\n\t# " << info_title << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void InformationScreen::DisplayUserInformation(
    const std::__cxx11::string &info_title, const double &value) const {
  cout << "\n\t# " << info_title << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void InformationScreen::DrawStrip() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
}

void InformationScreen::DisplayLogin(const std::__cxx11::string &login) const {
  DisplayUserInformation(account_messenger_.LoginText(), login);
}

void InformationScreen::DisplayPassword(
    const std::__cxx11::string &password) const {
  DisplayUserInformation(account_messenger_.PasswordText(), password);
}

void InformationScreen::DisplayCash(const int cash) const {
  DisplayUserInformation(account_messenger_.BalanceText(), cash);
}
