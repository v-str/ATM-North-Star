#include "registration_messenger.h"

void RegistrationMessenger::ShowRegistrationScreen() {
  console_editor_.AddEmptyLineNTimes(2);
  console_editor_.ClearScreen();

  console_editor_.WriteText(
      "\n\t   ********************\n"
      "\t   *   REGISTRATION   *\n"
      "\t   ********************\n\n");
}
