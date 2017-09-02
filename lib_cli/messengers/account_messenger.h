#ifndef ACCOUNT_MESSENGER_H
#define ACCOUNT_MESSENGER_H

#include <string>

class AccountMessenger {
 public:
  static void DisplayInfoLine(const std::string& info_title,
                              const std::string& info_line);

  static std::string LoginText() { return "Login: "; }
  static std::string CashText() { return "Balance: $"; }
  static std::string CreditText() { return "Credit: $"; }
  static std::string CreditTermText() { return "Credit term, month(s): "; }
  static std::string InterestRateText() { return "Interest rate, %: "; }
  static std::string MonthlyPaymentText() { return "Monthly payment: $"; }

 private:
  static void DisplayStrip();

  static constexpr int kNTimes = 45;
  static constexpr int kSleep = 100;
};

#endif  // ACCOUNT_MESSENGER_H
