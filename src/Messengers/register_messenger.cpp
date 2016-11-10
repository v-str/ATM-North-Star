#include "register_messenger.h"

#include <iostream>

void RegisterMessenger::ShowRegistrationScreen() const {
  text_editor_.ClearScreen();
  std::cout << "\n\t\t   ********************\n"
               "\t\t   *   REGISTRATION   *\n"
               "\t\t   ********************\n";
}
