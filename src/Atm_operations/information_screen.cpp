#include "information_screen.h"

#include "cash_operator.h"
#include "user_identifier.h"

void InformationScreen::DisplayLogin(const std::string &login) const {
  DisplayUserInformation(account_messenger_.LoginText(), login);
}

void InformationScreen::DisplayPassword(const std::string &password) const {
  DisplayUserInformation(account_messenger_.PasswordText(), password);
}

void InformationScreen::DisplayCash(int cash) const {
  DisplayUserInformation(account_messenger_.BalanceText(), cash);
}

void InformationScreen::DisplayCredit(int credit) const {
  DisplayUserInformation(account_messenger_.CreditText(), credit);
}

void InformationScreen::DisplayPayment(double payment) const {
  DisplayUserInformation(account_messenger_.PaymentText(), payment);
}

void InformationScreen::DisplayCreditMonth(int credit_month) const {
  DisplayUserInformation(account_messenger_.TermText(), credit_month);
}

void InformationScreen::DisplayInfoLine(const std::string &info_title,
                                        const std::string &info_line) const {
  account_messenger_.DisplayInfoLine(info_title, info_line);
}
