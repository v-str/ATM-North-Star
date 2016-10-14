#include "information_screen.h"

void InformationScreen::DisplayUserInformation(const std::string &info_title,
                                               const std::string &value) const {
  cout << "\n\t# " << info_title << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
  utility_.Sleep(kSleep);
}

void InformationScreen::DisplayUserInformation(const std::string &info_title,
                                               int value) const {
  DisplayUserInformation(info_title, std::to_string(value));
}

void InformationScreen::DisplayUserInformation(const std::string &info_title,
                                               const double &value) const {
  DisplayUserInformation(info_title, std::to_string(value));
}

void InformationScreen::DrawStrip() {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kNTimes);
}

void InformationScreen::DisplayLogin(const std::string &login) const {
  DisplayUserInformation(account_messenger_.LoginText(), login);
}

void InformationScreen::DisplayPassword(const std::string &password) const {
  DisplayUserInformation(account_messenger_.PasswordText(), password);
}

void InformationScreen::DisplayCash(const int cash) const {
  DisplayUserInformation(account_messenger_.BalanceText(), cash);
}

void InformationScreen::DisplayCredit(const int credit) const {
  DisplayUserInformation(account_messenger_.CreditText(), credit);
}

void InformationScreen::DisplayPayment(const double payment) const {
  DisplayUserInformation(account_messenger_.PaymentText(), payment);
}

void InformationScreen::DisplayCreditMonth(const int credit_month) const {
  DisplayUserInformation(account_messenger_.TermText(), credit_month);
}
