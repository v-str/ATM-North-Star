#include <credit_calculator_messenger.h>

#include <application_messenger.h>
#include <console_editor.h>

void CreditCalculatorMessenger::DisplayCalculatorDescription() {
  DisplayCorrectInputOrder();
  DisplayNotification();
  DisplayLogo();
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

// void CreditCalculatorMessenger::ClearScreen() { ConsoleEditor::ClearScreen();
// }

void CreditCalculatorMessenger::DisplayCorrectInputOrder() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "############################################################\n"
      "##                                                        ##\n"
      "##   Choose:                                              ##\n"
      "##                                                        ##\n"
      "##     1. Sum of credit, $                                ##\n"
      "##     2. Credit interest rate                            ##\n"
      "##     3. Credit term in months                           ##\n"
      "##                                                        ##\n"
      "############################################################\n\n");
}

void CreditCalculatorMessenger::DisplayNotification() {
  ConsoleEditor::WriteText(
      "############################################################\n"
      "##                                                        ##\n"
      "## Notification:                                          ##\n"
      "## Credit calculator shows annuity payments.              ##\n"
      "## Credit sum must be from $10000 to $500000.             ##\n"
      "## Credit interest rate must be from 5% to 50% per year   ##\n"
      "##  from initial sum of credit.                           ##\n"
      "## Credit term must be from 1 month to 60 months.         ##\n"
      "##                                                        ##\n"
      "############################################################\n\n");
  ApplicationMessenger::PressEnterToContinue();
}

void CreditCalculatorMessenger::DisplayLogo() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "##################################################################\n"
      "#                                                                #\n"
      "#                       Credit Calculator                        #\n"
      "#                                                                #\n"
      "##################################################################\n\n");
}
