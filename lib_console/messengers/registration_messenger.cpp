#include <registration_messenger.h>

#include <console_editor.h>

void RegistrationMessenger::ShowRegistrationScreen() {
  ConsoleEditor::AddEmptyLineNTimes(2);
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText(
      "\n\t   ********************\n"
      "\t   *   REGISTRATION   *\n"
      "\t   ********************\n\n");
}
