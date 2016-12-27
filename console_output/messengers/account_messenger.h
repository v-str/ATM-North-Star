#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <sstream>
#include <string>

#include "output_configuration/console_editor.h"

class AccountMessenger {
 public:
  void DisplayStrip() const;
  void DisplayInfoLine(const std::string &info_title,
                       const std::string &info_line) const;

  static std::string LoginText() { return "Login: "; }
  static std::string PasswordText() { return "Password: "; }
  static std::string BalanceText() { return "Balance: $"; }
  static std::string CreditText() { return "Credit: $"; }
  static std::string PaymentText() { return "Monthly payment: $"; }
  static std::string TermText() { return "Credit term: "; }

 private:
  static const int kNTimes = 45;
  static const int kSleep = 100;

  ConsoleEditor console_editor_;
};

#endif  // ACCOUNT_MESSENGER_H
