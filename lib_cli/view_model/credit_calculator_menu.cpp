#include <credit_calculator_menu.h>

#include <credit_calculator_messenger.h>
#include <user_input_handler.h>

void CreditCalculatorMenu::RunCreditCalculator() {
  CreditCalculatorMessenger::DisplayCalculatorDescription();
  RequestDataForCredit();
}

void CreditCalculatorMenu::RequestDataForCredit() {
  RequestCreditSum();
  RequestCreditInterestRate();
  RequestAmountOfMonths();
}

void CreditCalculatorMenu::RequestCreditSum() {
  CreditCalculatorMessenger::DisplayCreditSumRequest();
  credit_sum_ = GetUserInput();
}

void CreditCalculatorMenu::RequestCreditInterestRate() {
  CreditCalculatorMessenger::DisplayInterestRateRequest();
  credit_interest_rate_ = GetUserInput();
}

void CreditCalculatorMenu::RequestAmountOfMonths() {
  CreditCalculatorMessenger::DisplayAmountOfMonthRequest();
  amount_of_months_ = GetUserInput();
}

std::string CreditCalculatorMenu::GetUserInput() {
  UserInputHandler user_input_handler;
  std::string user_input = user_input_handler.GetStringInputFromUser();
  return user_input;
}
