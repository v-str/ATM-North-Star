#include <credit_messenger.h>

#include <console_editor.h>
#include <text_writer.h>

void CreditMessenger::DisplayCreditMenu() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::WriteText(
      "\t##############################\n"
      "\t##                          ##\n"
      "\t##   1. Credit              ##\n"
      "\t##   2. Calculator          ##\n"
      "\t##   3. Main menu           ##\n"
      "\t##   4. Quit                ##\n"
      "\t##                          ##\n"
      "\t##############################\n");
  ConsoleEditor::AddEmptyLineNTimes(1);
  ConsoleEditor::WriteText("\t## Enter: ");
}
