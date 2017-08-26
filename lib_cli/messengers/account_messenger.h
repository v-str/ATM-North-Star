#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <string>

class AccountMessenger {
 public:
  static void DisplayInfoLine(const std::string& info_title,
                              const std::string& info_line);

  static std::string LoginText() { return "Login: "; }
  static std::string BalanceText() { return "Balance: $"; }
  static std::string CreditText() { return "Credit: $"; }
  static std::string PaymentText() { return "Monthly payment: $"; }
  static std::string TermText() { return "Credit term: "; }

 private:
  static void DisplayStrip();

  static constexpr int kNTimes = 45;
  static constexpr int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
