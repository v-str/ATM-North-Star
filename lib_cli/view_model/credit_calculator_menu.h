#ifndef CREDIT_CALCULATOR_MENU_H
#define CREDIT_CALCULATOR_MENU_H

class CreditCalculatorMenu {
 public:
  void ShowCreditCalculatorDescription();
  void RunFillingCreditDatasProcess();

 private:
  void RequestCreditSum();
  void RequestCreditInterestRate();
  void RequestAmountOfMonths();

  template <typename T>
  T GetUserInput();

  int credit_sum_;
  double credit_interest_rate_;
  int amount_of_months_;
};

#endif  // CREDIT_CALCULATOR_MENU_H
