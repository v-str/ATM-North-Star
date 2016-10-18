#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <sstream>
#include <string>

#include "system_utility.h"

using std::cout;

class AccountMessenger {
 public:
  void DisplayStrip() const;
  void DisplayInfoLine(const std::string &info_title,
                       const std::stringstream &stream) const;

  inline std::string LoginText() const { return "Login: "; }
  inline std::string PasswordText() const { return "Password: "; }
  inline std::string BalanceText() const { return "Balance: $"; }
  inline std::string CreditText() const { return "Credit: $"; }
  inline std::string PaymentText() const { return "Monthly payment: $"; }
  inline std::string TermText() const { return "Credit term: $"; }

 private:
  SystemUtility utility_;

  static const int kNTimes = 45;
  static const int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
