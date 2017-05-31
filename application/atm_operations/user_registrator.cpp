#include <user_registrator.h>

#include <identification_messenger.h>
#include <registration_messenger.h>

void UserRegistrator::RegisterUser(AtmUser& atm_user) {
  SetRegistrationStatus(false);

  RegistrationMessenger::ShowRegistrationScreen();

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

bool UserRegistrator::SetRegistrationStatus() const {
  return registration_status_;
}

std::string UserRegistrator::GetUserLogin() const { return login_; }

void UserRegistrator::EnterLogin(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialLoginText();
  atm_user.SetLogin(provider_.GetLoginFromUser());
}

void UserRegistrator::EnterPassword(AtmUser& atm_user) {
  IdentificationMessenger::ShowInitialPasswordText();
  atm_user.SetPassword(provider_.GetPasswordFromUser());
}

void UserRegistrator::SetRegistrationStatus(bool registration_status) {
  registration_status_ = registration_status;
}
