#include <credit_calculator_messenger.h>

#include <application_messenger.h>
#include <console_editor.h>

void CreditCalculatorMessenger::DisplayCalculatorDescription() {
  DisplayLogo();
  DisplayNotification();
}

void CreditCalculatorMessenger::DisplayCreditSumRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("## Sum of credit, ($): ");
}

void CreditCalculatorMessenger::DisplayInterestRateRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("## Interest rate, (%): ");
}

void CreditCalculatorMessenger::DisplayAmountOfMonthRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("## Credit term, (months): ");
}

void CreditCalculatorMessenger::DisplayErrorLogo() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n## Calculation cannot be performed.\n"
      "## Input data contain next error(s):\n\n");
}

void CreditCalculatorMessenger::DisplayError(const std::string& error_text) {
  ConsoleEditor::WriteTextWithDelayPerSymbol("## " + error_text + "\n");
}

void CreditCalculatorMessenger::DisplayNotification() {
  ConsoleEditor::WriteText(
      "##################################################################\n"
      "##                                                              ##\n"
      "## Notification:                                                ##\n"
      "##                                                              ##\n"
      "## 1. Credit calculator shows annuity payments.                 ##\n"
      "##                                                              ##\n"
      "## 2. Credit sum must be from $5000 to $5000000.                ##\n"
      "##                                                              ##\n"
      "## 3. Credit interest rate must be from 5% to 50% per year      ##\n"
      "##  from initial sum of credit.                                 ##\n"
      "##                                                              ##\n"
      "## 4. Credit term must be from 1 month to 60 months.            ##\n"
      "##                                                              ##\n"
      "##################################################################\n\n");
  ApplicationMessenger::PressEnterToContinue();
}

void CreditCalculatorMessenger::DisplayLogo() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "##################################################################\n"
      "##                                                              ##\n"
      "##                      Credit Calculator                       ##\n"
      "##                                                              ##\n"
      "##################################################################\n\n");
}
