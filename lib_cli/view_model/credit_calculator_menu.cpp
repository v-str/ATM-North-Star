#include <credit_calculator_menu.h>

#include <credit_calculator_messenger.h>

void CreditCalculatorMenu::RunCreditCalculator() {
  CreditCalculatorMessenger::DisplayCalculatorDescription();
  RequestDataForCredit();
}

void CreditCalculatorMenu::RequestDataForCredit() {
  RequestCreditSum();
  RequestCreditInterestRate();
  RequestAmountOfMonths();
}

int CreditCalculatorMenu::CreditSum() const { return credit_sum_; }

double CreditCalculatorMenu::CreditInterestRate() const {
  return credit_interest_rate_;
}

int CreditCalculatorMenu::AmountOfMonths() const { return amount_of_months_; }

void CreditCalculatorMenu::RequestCreditSum() {
  CreditCalculatorMessenger::DisplayCreditSumRequest();
  credit_sum_ = user_input_handler_.GetDigitInputFromUser();
}

void CreditCalculatorMenu::RequestCreditInterestRate() {
  CreditCalculatorMessenger::DisplayInterestRateRequest();
  credit_interest_rate_ = user_input_handler_.GetDoubleDigitFromUser();
}

void CreditCalculatorMenu::RequestAmountOfMonths() {
  CreditCalculatorMessenger::DisplayAmountOfMonthRequest();
  amount_of_months_ = user_input_handler_.GetDigitInputFromUser();
}
