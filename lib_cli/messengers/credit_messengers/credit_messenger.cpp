#include <credit_messenger.h>

#include <console_editor.h>
#include <text_writer.h>

void CreditMessenger::DisplayCreditMenu() {
  ConsoleEditor::WriteText(
      "\n\n\t##############################\n"
      "\t##                          ##\n"
      "\t##   1. Credit              ##\n"
      "\t##   2. Calculator          ##\n"
      "\t##   3. Main menu           ##\n"
      "\t##   4. Quit                ##\n"
      "\t##                          ##\n"
      "\t##############################\n\n"
      "\t## Enter: ");
}
