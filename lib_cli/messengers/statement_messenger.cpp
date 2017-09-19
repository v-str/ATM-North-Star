#include <statement_messenger.h>

#include <string>

#include <console_editor.h>

void StatementMessenger::ShowStatement(double amount_of_cash) {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\t##################\n"
      "\t#                #\n"
      "\t#  28 Green st.  #\n"
      "\t#   New - York   #\n"
      "\t#                #\n"
      "\t#   NORTH BANK   #\n"
      "\t#                #\n"
      "\t# Balance:       #\n"
      "\t#  $ " +
      std::to_string(amount_of_cash) + "spaces" + "#\n" +
      "\t#                #\n"
      "\t#  HAVE A NICE   #\n"
      "\t#      DAY       #\n"
      "\t#                #\n"
      "\t##################\n");

  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
  ConsoleEditor::IgnoreCinLine();
}
