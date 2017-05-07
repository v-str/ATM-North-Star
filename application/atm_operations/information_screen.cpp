#include <information_screen.h>

#include <account_messenger.h>

void InformationScreen::DisplayLogin(const std::string& login) const {
  DisplayUserInformation(AccountMessenger::LoginText(), login);
}

void InformationScreen::DisplayPassword(const std::string& password) const {
  DisplayUserInformation(AccountMessenger::PasswordText(), password);
}

void InformationScreen::DisplayCash(int cash) const {
  DisplayUserInformation(AccountMessenger::BalanceText(), cash);
}

void InformationScreen::DisplayCredit(int credit) const {
  DisplayUserInformation(AccountMessenger::CreditText(), credit);
}

void InformationScreen::DisplayPayment(double payment) const {
  DisplayUserInformation(AccountMessenger::PaymentText(), payment);
}

void InformationScreen::DisplayCreditMonth(int credit_month) const {
  DisplayUserInformation(AccountMessenger::TermText(), credit_month);
}

void InformationScreen::DisplayLine(const std::string& info_title,
                                    const std::string& info_line) const {
  AccountMessenger::DisplayInfoLine(info_title, info_line);
}
