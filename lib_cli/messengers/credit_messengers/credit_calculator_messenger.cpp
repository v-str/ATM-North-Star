#include <credit_calculator_messenger.h>

#include <console_editor.h>

void CreditCalculatorMessenger::DisplayCalculatorDescription() {
  ConsoleEditor::ClearScreen();

  ConsoleEditor::WriteText(
      "\t################################################\n"
      "\t##                                            ##\n"
      "\t##              Credit Calculator             ##\n"
      "\t##                                            ##\n"
      "\t##   Choose:                                  ##\n"
      "\t##                                            ##\n"
      "\t##     1. Sum of credit, $                    ##\n"
      "\t##     2. Credit interest rate                ##\n"
      "\t##     3. Credit term in months               ##\n"
      "\t##                                            ##\n"
      "\t##   ( Note that calculation is presented as  ##\n"
      "\t##     annuity payment form )                 ##\n"
      "\t##                                            ##\n"
      "\t################################################\n\n"
      "\t  Press \"Enter\" to continue...");
  ConsoleEditor::IgnoreCinLine();
}
