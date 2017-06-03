#include <registrator.h>

#include <authentication_messenger.h>
#include <registration_messenger.h>

void Registrator::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ConfirmRegistration();
  if (user_want_to_registrate) {
    RunRegistrationProcedure();
  }
}

void Registrator::ConfirmRegistration() {
  for (;;) {
    int user_choice = menu_input_.GetDigitInputFromUser();

    if (user_choice == kStartRegistration) {
      user_want_to_registrate = true;
      break;
    } else if (user_choice == kSymbolQuit || user_choice == kDigitQuit) {
      user_want_to_registrate = false;
      break;
    }

    RegistrationMessenger::ShowIncorrectRegistrationConfirmation();
  }
}

void Registrator::RunRegistrationProcedure() {
  AuthenticationMessenger::ClearScreen();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
  authenticaton_handler_.HandleAuthenticationData(login_, password_);
}

void Registrator::GetLoginStringFromUser() {
  AuthenticationMessenger::DisplayLoginText();
  login_ = user_input_.GetStringInputFromUser();
}

void Registrator::GetPasswordStringFromUser() {
  AuthenticationMessenger::DisplayPasswordText();
  password_ = user_input_.GetStringInputFromUser();
}
