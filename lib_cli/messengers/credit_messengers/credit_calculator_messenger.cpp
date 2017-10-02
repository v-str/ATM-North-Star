#include <credit_calculator_messenger.h>

#include <application_messenger.h>
#include <console_editor.h>

void CreditCalculatorMessenger::DisplayCalculatorDescription() {
  DisplayCorrectInputOrder();
  DisplayNotification();
  DisplayLogo();
}

void CreditCalculatorMessenger::DisplayCreditSumRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Sum of credit, ($): ");
}

void CreditCalculatorMessenger::DisplayInterestRateRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Interest rate, (%): ");
}

void CreditCalculatorMessenger::DisplayAmountOfMonthRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Credit term, (months): ");
}

void CreditCalculatorMessenger::DisplayErrorLogo() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t## Calculation cannot be performed.\n"
      "\t## Input data contain next error(s):\n\n");
}

void CreditCalculatorMessenger::DisplayError(const std::string& error_text) {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## " + error_text + "\n");
}

// void CreditCalculatorMessenger::ClearScreen() { ConsoleEditor::ClearScreen();
// }

void CreditCalculatorMessenger::DisplayCorrectInputOrder() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\t############################################################\n"
      "\t##                                                        ##\n"
      "\t##   Choose:                                              ##\n"
      "\t##                                                        ##\n"
      "\t##     1. Sum of credit, $                                ##\n"
      "\t##     2. Credit interest rate                            ##\n"
      "\t##     3. Credit term in months                           ##\n"
      "\t##                                                        ##\n"
      "\t############################################################\n\n");
}

void CreditCalculatorMessenger::DisplayNotification() {
  ConsoleEditor::WriteText(
      "\t############################################################\n"
      "\t##                                                        ##\n"
      "\t## Notification:                                          ##\n"
      "\t## Credit calculator shows annuity payments.              ##\n"
      "\t## Credit sum must be from $10000 to $500000.             ##\n"
      "\t## Credit interest rate must be from 5% to 50% per year   ##\n"
      "\t##  from initial sum of credit.                           ##\n"
      "\t## Credit term must be from 1 month to 60 months.         ##\n"
      "\t##                                                        ##\n"
      "\t############################################################\n\n");
  ApplicationMessenger::PressEnterToContinue();
}

void CreditCalculatorMessenger::DisplayLogo() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\t############################################################\n"
      "\t#                                                          #\n"
      "\t#                    Credit Calculator                     #\n"
      "\t#                                                          #\n"
      "\t############################################################\n\n");
}
