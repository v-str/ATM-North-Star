#include <registrator.h>

#include <logon_messenger.h>
#include <registration_messenger.h>

void Registrator::RunRegistrationMenu() {
  RegistrationMessenger::ShowRegistrationLogo();
  RegistrationMessenger::ShowRegistrationReference();
  ProcessMenuUserInput();
  if (user_want_to_registrate) {
    RunRegistrationProcedure();
  }
}

void Registrator::ProcessMenuUserInput() {
  for (;;) {
    int user_choice = menu_input_.GetDigitInputFromUser();

    if (user_choice == kRegistration) {
      user_want_to_registrate = true;
      break;
    } else if (user_choice == kSymbolQuit || user_choice == kDigitQuit) {
      user_want_to_registrate = false;
      break;
    } else {
      RegistrationMessenger::ShowIncorrectInput();
    }
  }
}

void Registrator::RunRegistrationProcedure() {
  for (;;) {
    GetRegistratoinDataFromUser();
    logon_handler_.HandleLogonData(login_, password_);
    if (logon_handler_.IsAuthenticationOk()) {
      // Initialize user data in ATM
      // Run transaction menu
      break;
    } else {
      ProcessMenuUserInput();
      if (!user_want_to_registrate) {
        break;
      }
    }
  }
}

void Registrator::GetRegistratoinDataFromUser() {
  RegistrationMessenger::ShowRegistrationLogo();
  GetLoginStringFromUser();
  GetPasswordStringFromUser();
}

void Registrator::GetLoginStringFromUser() {
  login_ = user_input_.GetStringInputFromUser();
}

void Registrator::GetPasswordStringFromUser() {
  password_ = user_input_.GetStringInputFromUser();
}
