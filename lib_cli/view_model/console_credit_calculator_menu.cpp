#include <console_credit_calculator_menu.h>

#include <credit_calculator_messenger.h>

void ConsoleCreditCalculatorMenu::RunCreditCalculator() {
  CreditCalculatorMessenger::DisplayCalculatorDescription();
  RequestDataForCredit();
}

void ConsoleCreditCalculatorMenu::RequestDataForCredit() {
  RequestCreditSum();
  RequestCreditInterestRate();
  RequestAmountOfMonths();
}

int ConsoleCreditCalculatorMenu::CreditSum() const { return credit_sum_; }

double ConsoleCreditCalculatorMenu::CreditInterestRate() const {
  return credit_interest_rate_;
}

int ConsoleCreditCalculatorMenu::AmountOfMonths() const {
  return amount_of_months_;
}

void ConsoleCreditCalculatorMenu::ShowIncorrectInputError(
    const std::vector<std::string>& error_list) {
  CreditCalculatorMessenger::DisplayErrorLogo();
  for (auto it = error_list.begin(); it != error_list.end(); ++it) {
    CreditCalculatorMessenger::DisplayError(*it);
  }
  CreditCalculatorMessenger::PressEnterToContinue();
}

void ConsoleCreditCalculatorMenu::RequestCreditSum() {
  CreditCalculatorMessenger::DisplayCreditSumRequest();
  credit_sum_ = user_input_handler_.GetDigitInputFromUser();
}

void ConsoleCreditCalculatorMenu::RequestCreditInterestRate() {
  CreditCalculatorMessenger::DisplayInterestRateRequest();
  credit_interest_rate_ = user_input_handler_.GetDoubleDigitFromUser();
}

void ConsoleCreditCalculatorMenu::RequestAmountOfMonths() {
  CreditCalculatorMessenger::DisplayAmountOfMonthRequest();
  amount_of_months_ = user_input_handler_.GetDigitInputFromUser();
}
