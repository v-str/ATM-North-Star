#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <string>

class AccountMessenger {
 public:
  static void DisplayInfoLine(const std::string& info_title,
                              const std::string& info_line);

  static std::string LoginText() { return "Login: "; }
  static std::string CashText() { return "Balance: $"; }
  static std::string PasswordTooltip() { return "Password tooltip: "; }

 private:
  static void DisplayStrip();

  static const int kNTimes = 35;
  static const int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
