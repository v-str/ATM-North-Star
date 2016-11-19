#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include <string>

#include "account_messenger.h"

class InformationScreen {
 public:
  void DisplayLogin(const std::string &login) const;
  void DisplayPassword(const std::string &password) const;
  void DisplayCash(int cash) const;
  void DisplayCredit(int credit) const;
  void DisplayPayment(double payment) const;
  void DisplayCreditMonth(int credit_month) const;

  void DisplayUserInformation(const std::string &info_title,
                              const std::string &value) const;

  void DisplayUserInformation(const std::string &info_title, int value) const;

  void DisplayUserInformation(const std::string &info_title,
                              double value) const;

 private:
  static const int kNTimes = 45;
  static const int kSleep = 100;

  AccountMessenger account_messenger_;
};

#endif  // INFORMATIONSCREEN_H
