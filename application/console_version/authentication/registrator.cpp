#include <registrator.h>

#include <identification_messenger.h>
#include <registration_messenger.h>

void Registrator::RunRegistration(AtmUser& atm_user) {
  SetRegistrationStatus(false);

  RegistrationMessenger::ShowRegistrationScreen();
  RegistrationMessenger::ShowRegistrationReference();

  EnterLogin(atm_user);
  if (atm_user.IsNormalLogin()) {
    EnterPassword(atm_user);
    if (atm_user.IsNormalPass()) {
      notice_messenger_.ShowAcceptableMessageFrame();
      SetRegistrationStatus(true);
    } else {
      notice_messenger_.ShowIncorrectFormatPassword();
    }
  } else {
    notice_messenger_.ShowIncorrectLoginFrame();
  }
}

bool Registrator::SetRegistrationStatus() const { return registration_status_; }

std::string Registrator::GetUserLogin() const { return login_; }

// new code
void Registrator::RunRegistration() {
  RegistrationMessenger::ShowRegistrationScreen();
  RegistrationMessenger::ShowRegistrationReference();
}

void Registrator::EnterLogin(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialLoginText();
  atm_user.SetLogin(provider_.GetLoginFromUser());
}

void Registrator::EnterPassword(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialPasswordText();
  atm_user.SetPassword(provider_.GetPasswordFromUser());
}

void Registrator::SetRegistrationStatus(bool registration_status) {
  registration_status_ = registration_status;
}
