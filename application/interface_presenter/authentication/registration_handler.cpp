#include <registration_handler.h>

#include <registration_status_messenger.h>

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
  login_status_ = authenticator_.InspectLoginString(login);
  switch (login_status_) {
    case ATM::RegistrationStatus::kCorrectLogin:
      RegistrationStatusMessenger::CorrectLoginMessage();
      is_login_ok_ = true;
      break;
    case ATM::RegistrationStatus::kShortLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kShortLoginLength);
      break;
    case ATM::RegistrationStatus::kLongLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kLongLoginLength);
      break;
    case ATM::RegistrationStatus::kSpecialSymbols:
      RegistrationStatusMessenger::LoginContainSpecialSymbol();
      break;
    case ATM::RegistrationStatus::kBeginWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case ATM::RegistrationStatus::kEndWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case ATM::RegistrationStatus::kAdjacentSpaces:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case ATM::RegistrationStatus::kContainOnlyDigits:
      RegistrationStatusMessenger::LoginContainOnlyDigits();
      break;
    case ATM::RegistrationStatus::kEmptyString:
      RegistrationStatusMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void RegistrationHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
  switch (password_status_) {
    case ATM::RegistrationStatus::kCorrectPassword:
      RegistrationStatusMessenger::CorrectPasswordMessage();
      is_password_ok_ = true;
      break;
    case ATM::RegistrationStatus::kShortPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kShortPasswordLength);
      break;
    case ATM::RegistrationStatus::kLongPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kLongPasswordLength);
      break;
    case ATM::RegistrationStatus::kContainSpaceSymbol:
      RegistrationStatusMessenger::PasswordContainSpaceSymbol();
      break;
    case ATM::kEmptyString:
      RegistrationStatusMessenger::PasswordEmpty();
      break;
    default:
      break;
  }
  RegistrationStatusMessenger::AddEmptyLines(2);
}
