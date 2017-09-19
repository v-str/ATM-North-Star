#include <statement_messenger.h>

#include <string>

#include <console_editor.h>

void StatementMessenger::ShowStatement(double amount_of_cash) {
  ConsoleEditor::ClearScreen();
  //  ConsoleEditor::WriteText(
  //      "\t##################\n"
  //      "\t#                #\n"
  //      "\t#  28 Green st.  #\n"
  //      "\t#   New - York   #\n"
  //      "\t#                #\n"
  //      "\t#   NORTH BANK   #\n"
  //      "\t#                #\n"
  //      "\t# Balance:       #\n"
  //      "\t#  $ " +
  //      std::to_string(amount_of_cash) + "spaces" + "#\n" +
  //      "\t#                #\n"
  //      "\t#  HAVE A NICE   #\n"
  //      "\t#      DAY       #\n"
  //      "\t#                #\n"
  //      "\t##################\n");

  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
  ConsoleEditor::IgnoreCinLine();
}

void StatementMessenger::DrawFilledLine() {
  std::string filled_line;
  for (int i = 0; i < kFilledLineLength; ++i) {
    filled_line.append("#");
  }
  ConsoleEditor::WriteText(filled_line);
}

void StatementMessenger::DrawEmptyLine() {
  std::string empty_line = "#";
  for (int i = 0; i < kEmptyLineLength; ++i) {
    empty_line.append(" ");
  }
  empty_line.append("#");

  ConsoleEditor::WriteText(empty_line);
}
