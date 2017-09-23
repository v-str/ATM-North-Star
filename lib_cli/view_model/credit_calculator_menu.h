#ifndef CREDIT_CALCULATOR_MENU_H
#define CREDIT_CALCULATOR_MENU_H

#include <string>

class CreditCalculatorMenu {
 public:
  void RunCreditCalculator();
  void RunFillingCreditDatasProcess();

 private:
  void RequestCreditSum();
  void RequestCreditInterestRate();
  void RequestAmountOfMonths();

  std::string GetUserInput();

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;
};

#endif  // CREDIT_CALCULATOR_MENU_H
