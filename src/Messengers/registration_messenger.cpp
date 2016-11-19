#include "registration_messenger.h"

#include <iostream>

#include "console_editor.h"

void RegistrationMessenger::ShowRegistrationScreen() {
  ConsoleEditor::ClearScreen();
  std::cout << "\n\t\t   ********************\n"
               "\t\t   *   REGISTRATION   *\n"
               "\t\t   ********************\n";
}
