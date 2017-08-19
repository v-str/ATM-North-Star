#include <atm_registration_handler.h>

ATM::RegistrationStatus AtmRegistrationHandler::HandleLoginString(
    const std::string login) {
  ATM::RegistrationStatus login_status =
      registration_inpector_.InspectLoginString(login);
  return login_status;
}

ATM::RegistrationStatus AtmRegistrationHandler::HandlePasswordString(
    const std::string password) {
  ATM::RegistrationStatus password_status =
      registration_inpector_.InspectPasswordString(password);
  return password_status;
}
