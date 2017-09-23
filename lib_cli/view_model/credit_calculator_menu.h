#ifndef CREDIT_CALCULATOR_MENU_H
#define CREDIT_CALCULATOR_MENU_H

#include <string>

class CreditCalculatorMenu {
 public:
  void RunCreditCalculator();
  void RequestDataForCredit();

  std::string CreditSum() const;
  std::string CreditInterestRate() const;
  std::string AmountOfMonths() const;

 private:
  void RequestCreditSum();
  void RequestCreditInterestRate();
  void RequestAmountOfMonths();

  std::string GetUserInput();

  std::string credit_sum_;
  std::string credit_interest_rate_;
  std::string amount_of_months_;
};

#endif  // CREDIT_CALCULATOR_MENU_H
