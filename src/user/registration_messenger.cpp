#include "registration_messenger.h"

static const int kMaxLenghtOfLogin = 21;
static const int kMaxLenghtOfPassword = 4;

void RegistrationMessenger::ShowRegistrationScreen() const {
  utility_.ClearScreen();
  cout << "\n\t\t   ********************\n"
          "\t\t   *   REGISTRATION   *\n"
          "\t\t   ********************\n";
}

void RegistrationMessenger::ShowInitialLoginText() const {
  cout << "\n\n\n\t\tLogin: ";
  utility_.WriteSymbolsNTimes('#', kMaxLenghtOfLogin);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfLogin);
}

void RegistrationMessenger::ShowInitialPasswordText() const {
  cout << "\t\tPassword: XXXX\b\b\b\b";
  utility_.WriteSymbolsNTimes('X', kMaxLenghtOfPassword);
  utility_.WriteSymbolsNTimes('\b', kMaxLenghtOfPassword);
}
