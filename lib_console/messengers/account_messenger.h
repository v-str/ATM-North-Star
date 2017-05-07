#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <string>

class AccountMessenger {
 public:
  void DisplayStrip() const;
  void DisplayInfoLine(const std::string& info_title,
                       const std::string& info_line) const;

  std::string LoginText() const { return "Login: "; }
  std::string PasswordText() const { return "Password: "; }
  std::string BalanceText() const { return "Balance: $"; }
  std::string CreditText() const { return "Credit: $"; }
  std::string PaymentText() const { return "Monthly payment: $"; }
  std::string TermText() const { return "Credit term: "; }

 private:
  const int kNTimes = 45;
  const int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
