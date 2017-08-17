#include <logon_handler.h>

#include <registration_status_messenger.h>

void LogonHandler::HandleLogonData(const std::string login,
                                   const std::string& password) {
  HandleLoginString(login);
  HandlePasswordString(password);
}

bool LogonHandler::IsAuthenticationOk() const {
  bool authentication_status = is_login_ok_ && is_password_ok_;
  return authentication_status;
}

void LogonHandler::HandleLoginString(const std::string& login) {
  login_status_ = authenticator_.InspectLoginString(login);
  switch (login_status_) {
    case ATM::LogonStatus::kCorrectLogin:
      RegistrationStatusMessenger::CorrectLoginMessage();
      is_login_ok_ = true;
      break;
    case ATM::LogonStatus::kShortLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kShortLoginLength);
      break;
    case ATM::LogonStatus::kLongLogin:
      RegistrationStatusMessenger::LoginLengthStatus(
          RegistrationStatusMessenger::kLongLoginLength);
      break;
    case ATM::LogonStatus::kSpecialSymbols:
      RegistrationStatusMessenger::LoginContainSpecialSymbol();
      break;
    case ATM::LogonStatus::kBeginWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case ATM::LogonStatus::kEndWithSpace:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case ATM::LogonStatus::kAdjacentSpaces:
      RegistrationStatusMessenger::LoginContainIncorrectSpacePosition(
          RegistrationStatusMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case ATM::LogonStatus::kContainOnlyDigits:
      RegistrationStatusMessenger::LoginContainOnlyDigits();
      break;
    case ATM::LogonStatus::kEmptyString:
      RegistrationStatusMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void LogonHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
  switch (password_status_) {
    case ATM::LogonStatus::kCorrectPassword:
      RegistrationStatusMessenger::CorrectPasswordMessage();
      is_password_ok_ = true;
      break;
    case ATM::LogonStatus::kShortPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kShortPasswordLength);
      break;
    case ATM::LogonStatus::kLongPassword:
      RegistrationStatusMessenger::PasswordLength(
          RegistrationStatusMessenger::kLongPasswordLength);
      break;
    case ATM::LogonStatus::kContainSpaceSymbol:
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
