#include <credit_calculator_messenger.h>

#include <console_editor.h>

void CreditCalculatorMessenger::DisplayCalculatorDescription() {
  ConsoleEditor::ClearScreen();

  ConsoleEditor::WriteText(
      "\t############################################################\n"
      "\t##                                                        ##\n"
      "\t##              Credit Calculator                         ##\n"
      "\t##                                                        ##\n"
      "\t##   Choose:                                              ##\n"
      "\t##                                                        ##\n"
      "\t##     1. Sum of credit, $                                ##\n"
      "\t##     2. Credit interest rate                            ##\n"
      "\t##     3. Credit term in months                           ##\n"
      "\t##                                                        ##\n"
      "\t##                                                        ##\n"
      "\t############################################################\n\n"
      "\t############################################################\n"
      "\t##                                                        ##\n"
      "\t## Notification:                                          ##\n"
      "\t## Credit calculator shows annuity payments.              ##\n"
      "\t## Credit sum must be from $10000 to $500000.             ##\n"
      "\t## Credit interest rate must be from 5% to 50% per year   ##\n"
      "\t##  from initial sum of credit.                           ##\n"
      "\t## Credit term must be from 1 month to 60 months.         ##\n"
      "\t##                                                        ##\n"
      "\t############################################################\n\n"
      "\t  Press \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
  ConsoleEditor::ClearScreen();
}

void CreditCalculatorMessenger::DisplayCreditSumRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Sum of credit: ");
}

void CreditCalculatorMessenger::DisplayInterestRateRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Interest rate, %: ");
}

void CreditCalculatorMessenger::DisplayAmountOfMonthRequest() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t## Credit term: ");
}

void CreditCalculatorMessenger::ClearScreen() { ConsoleEditor::ClearScreen(); }
