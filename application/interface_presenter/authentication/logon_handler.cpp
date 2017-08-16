#include <logon_handler.h>

#include <logon_messenger.h>

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
      LogonMessenger::CorrectLoginMessage();
      is_login_ok_ = true;
      break;
    case ATM::LogonStatus::kShortLogin:
      LogonMessenger::LoginLengthStatus(LogonMessenger::kShortLoginLength);
      break;
    case ATM::LogonStatus::kLongLogin:
      LogonMessenger::LoginLengthStatus(LogonMessenger::kLongLoginLength);
      break;
    case ATM::LogonStatus::kSpecialSymbols:
      LogonMessenger::LoginContainSpecialSymbol();
      break;
    case ATM::LogonStatus::kBeginWithSpace:
      LogonMessenger::LoginContainIncorrectSpacePosition(
          LogonMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case ATM::LogonStatus::kEndWithSpace:
      LogonMessenger::LoginContainIncorrectSpacePosition(
          LogonMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case ATM::LogonStatus::kAdjacentSpaces:
      LogonMessenger::LoginContainIncorrectSpacePosition(
          LogonMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case ATM::LogonStatus::kContainOnlyDigits:
      LogonMessenger::LoginContainOnlyDigits();
      break;
    case ATM::LogonStatus::kEmptyString:
      LogonMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void LogonHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
  switch (password_status_) {
    case ATM::LogonStatus::kCorrectPassword:
      LogonMessenger::CorrectPasswordMessage();
      is_password_ok_ = true;
      break;
    case ATM::LogonStatus::kShortPassword:
      LogonMessenger::PasswordLength(LogonMessenger::kShortPasswordLength);
      break;
    case ATM::LogonStatus::kLongPassword:
      LogonMessenger::PasswordLength(LogonMessenger::kLongPasswordLength);
      break;
    case ATM::LogonStatus::kContainSpaceSymbol:
      LogonMessenger::PasswordContainSpaceSymbol();
      break;
    case ATM::kEmptyString:
      LogonMessenger::PasswordEmpty();
      break;
    default:
      break;
  }
  LogonMessenger::AddEmptyLines(2);
}
