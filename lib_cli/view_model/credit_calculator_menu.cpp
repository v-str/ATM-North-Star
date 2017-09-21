#include <credit_calculator_menu.h>

#include <credit_calculator_messenger.h>

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
