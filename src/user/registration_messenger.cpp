#include "registration_messenger.h"

void RegistrationMessenger::ShowRegistrationScreen() const {
  utility_.ClearScreen();
  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";
}
