#include <atm_registration_handler.h>

ATM::RegistrationStatus AtmRegistrationHandler::HandleLoginString(
    const std::string login) {
  login_status_ = registration_inpector_.InspectLoginString(login);

  CheckLoginString();

  return login_status_;
}

ATM::RegistrationStatus AtmRegistrationHandler::HandlePasswordString(
    const std::string password) {
  password_status_ = registration_inpector_.InspectPasswordString(password);

  return password_status_;
}

void AtmRegistrationHandler::CheckLoginString() {
  if (login_status_ == ATM::RegistrationStatus::kCorrectLogin) {
    is_login_correct_ = true;
  } else {
    is_login_correct_ = false;
  }
}
