#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <string>

#include "system_utility.h"

using std::cout;

class AccountMessenger {
 public:
  void DisplayUserInformation(const std::string &info_title,
                              const std::string &value) const;

  void DisplayStrip();

  inline std::string GetLoginText() const { return "Login"; }
  inline std::string GetPasswordText() const { return "Password"; }
  inline std::string GetBalanceText() const { return "Balance"; }
  inline std::string GetCreditText() const { return "Credit"; }
  inline std::string GetPaymentText() const { return "Monthly payment"; }
  inline std::string GetTermText() const { return "Credit term"; }

 private:
  SystemUtility utility_;

  static const int kNTimes = 25;
  static const int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
