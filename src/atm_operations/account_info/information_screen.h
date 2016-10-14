#ifndef INFORMATION_SCREEN_H
#define INFORMATION_SCREEN_H

#include <string>

#include "account_messenger.h"
#include "cash_operator.h"
#include "system_utility.h"
#include "user_identifier.h"

using std::cout;

class InformationScreen {
 public:
  void DisplayLogin(const std::string &login) const;
  void DisplayPassword(const std::string &password) const;
  void DisplayCash(const int cash) const;
  void DisplayCredit(const int credit) const;
  void DisplayPayment(const double payment) const;
  void DisplayCreditMonth(const int credit_month) const;

  void DisplayUserInformation(const std::string &info_title,
                              const std::string &value) const;

  void DisplayUserInformation(const std::string &info_title, int value) const;

  void DisplayUserInformation(const std::string &info_title,
                              const double &value) const;

  void DrawStrip();

 private:
  AccountMessenger account_messenger_;
  SystemUtility utility_;

  static const int kNTimes = 45;
  static const int kSleep = 100;
};

#endif  // INFORMATIONSCREEN_H
