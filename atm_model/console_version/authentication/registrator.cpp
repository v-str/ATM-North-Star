#include <registrator.h>

#include <authentication_messenger.h>
#include <registration_messenger.h>

void cli::Registrator::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ConfirmRegistration();
  if (user_want_to_registrate) {
    RunRegistrationProcedure();
  }
}

void cli::Registrator::ConfirmRegistration() {
  for (;;) {
    int user_choice = menu_input_.GetDigitInputFromUser();

    if (user_choice == kStartRegistration) {
      user_want_to_registrate = true;
      break;
    } else if (user_choice == kSymbolQuit || user_choice == kDigitQuit) {
      AuthenticationMessenger::FarewellMessage();
      user_want_to_registrate = false;
      break;
    }

    RegistrationMessenger::ShowIncorrectRegistrationConfirmation();
  }
}

void cli::Registrator::RunRegistrationProcedure() {
  for (;;) {
    GetRegistratoinDataFromUser();
    authenticaton_handler_.HandleAuthenticationData(login_, password_);
    if (authenticaton_handler_.IsAuthenticationOk()) {
      // Initialize user data in ATM
      // Run transaction menu
      break;
    } else {
      AuthenticationMessenger::SuggestReenterAuthenticationData();
      ConfirmRegistration();
      if (!user_want_to_registrate) {
        break;
      }
    }
  }
}

void cli::Registrator::GetRegistratoinDataFromUser() {
  AuthenticationMessenger::ClearScreen();
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

void cli::Registrator::GetLoginStringFromUser() {
  AuthenticationMessenger::DisplayLoginText();
  login_ = user_input_.GetStringInputFromUser();
}

void cli::Registrator::GetPasswordStringFromUser() {
  AuthenticationMessenger::DisplayPasswordText();
  password_ = user_input_.GetStringInputFromUser();
}
