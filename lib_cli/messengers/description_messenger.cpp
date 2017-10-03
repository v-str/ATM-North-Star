#include <description_messenger.h>

#include <application_messenger.h>
#include <console_editor.h>

void DescriptionMessenger::ShowDescription() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "#############################################################\n"
      "#                                                           #\n"
      "# ATM North star is simple prototype of ATM,                #\n"
      "# which maintain basic ATM-operations like a                #\n"
      "# refill and cash withdrawal.                               #\n"
      "# Also it provide annuity payment calculator function.      #\n"
      "# It intended for Windows and Unix-based operation systems. #\n"
      "#                                                           #\n"
      "#############################################################\n\n");
  ApplicationMessenger::PressEnterToContinue();
}
