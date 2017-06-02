#include <registrator.h>

#include <authentication_messenger.h>
#include <registration_messenger.h>

void Registrator::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ConfirmRegistration();
  if (is_registration_status_ok) {
    RunRegistrationProcedure();
  }
}

void Registrator::ConfirmRegistration() {
  for (;;) {
    int user_choice = menu_input_.GetDigitInputFromUser();

    if (user_choice == kStartRegistration) {
      is_registration_status_ok = true;
      break;
    } else if (user_choice == kSymbolQuit || user_choice == kDigitQuit) {
      is_registration_status_ok = false;
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
