#include <registration_handler.h>

void RegistrationHandler::HandleRegistrationData(const std::string login,
                                                 const std::string& password) {
  HandleLoginString(login);
  HandlePasswordString(password);
}

bool RegistrationHandler::IsAuthenticationOk() const {
  bool authentication_status = is_login_ok_ && is_password_ok_;
  return authentication_status;
}

void RegistrationHandler::HandleLoginString(const std::string& login) {
  login_status_ = registration_inspector_.InspectLoginString(login);
  switch (login_status_) {
    case ATM::RegistrationStatus::kCorrectLogin:
      is_login_ok_ = true;
      break;
    case ATM::RegistrationStatus::kShortLogin:
      break;
    case ATM::RegistrationStatus::kLongLogin:
      break;
    case ATM::RegistrationStatus::kSpecialSymbols:
      break;
    case ATM::RegistrationStatus::kBeginWithSpace:
      break;
    case ATM::RegistrationStatus::kEndWithSpace:
      break;
    case ATM::RegistrationStatus::kAdjacentSpaces:
      break;
    case ATM::RegistrationStatus::kContainOnlyDigits:
      break;
    case ATM::RegistrationStatus::kEmptyString:
      break;
    default:
      break;
  }
}

void RegistrationHandler::HandlePasswordString(const std::string& password) {
  password_status_ = registration_inspector_.InspectPasswordString(password);
  switch (password_status_) {
    case ATM::RegistrationStatus::kCorrectPassword:
      is_password_ok_ = true;
      break;
    case ATM::RegistrationStatus::kShortPassword:
      break;
    case ATM::RegistrationStatus::kLongPassword:
      break;
    case ATM::RegistrationStatus::kContainSpaceSymbol:
      break;
    case ATM::kEmptyString:
      break;
    default:
      break;
  }
}
