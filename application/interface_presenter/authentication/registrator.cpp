#include <registrator.h>

#include <logon_messenger.h>
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
      LogonMessenger::FarewellMessage();
      user_want_to_registrate = false;
      break;
    }

    RegistrationMessenger::ShowIncorrectRegistrationConfirmation();
  }
}

void Registrator::RunRegistrationProcedure() {
  for (;;) {
    GetRegistratoinDataFromUser();
    authenticaton_handler_.HandleLogonData(login_, password_);
    if (authenticaton_handler_.IsAuthenticationOk()) {
      // Initialize user data in ATM
      // Run transaction menu
      break;
    } else {
      LogonMessenger::SuggestReenterAuthenticationData();
      ConfirmRegistration();
      if (!user_want_to_registrate) {
        break;
      }
    }
  }
}

void Registrator::GetRegistratoinDataFromUser() {
  LogonMessenger::ClearScreen();
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

void Registrator::GetLoginStringFromUser() {
  LogonMessenger::DisplayLoginText();
  login_ = user_input_.GetStringInputFromUser();
}

void Registrator::GetPasswordStringFromUser() {
  LogonMessenger::DisplayPasswordText();
  password_ = user_input_.GetStringInputFromUser();
}
