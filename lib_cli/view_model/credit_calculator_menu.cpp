#include <credit_calculator_menu.h>

#include <credit_calculator_messenger.h>
#include <user_input_handler.h>

void CreditCalculatorMenu::ShowCreditCalculatorDescription() {
  CreditCalculatorMessenger::DisplayCalculatorDescription();
}

void CreditCalculatorMenu::RunFillingCreditDatasProcess() {
  for (;;) {
    RequestCreditSum();
    RequestCreditInterestRate();
    RequestAmountOfMonths();
  }
}

void CreditCalculatorMenu::RequestCreditSum() {}

void CreditCalculatorMenu::RequestCreditInterestRate() {}

void CreditCalculatorMenu::RequestAmountOfMonths() {}

template <typename T>
T CreditCalculatorMenu::GetUserInput() {
  UserInputHandler user_input_handler;
  T user_input = user_input_handler.GetStringInputFromUser();
  return user_input;
}
