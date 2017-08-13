#include <logon_handler.h>

#include <authentication_messenger.h>

void LogonHandler::HandleLogonData(
    const std::string login, const std::string& password) {
  HandleLoginString(login);
  HandlePasswordString(password);
}

bool LogonHandler::IsAuthenticationOk() const {
  bool authentication_status = is_login_ok_ && is_password_ok_;
  return authentication_status;
}

void LogonHandler::HandleLoginString(const std::string& login) {
  AuthenticationMessenger::ClearScreen();
  login_status_ = authenticator_.InspectLoginString(login);
  switch (login_status_) {
    case ATM::AuthenticationStatus::kCorrectLogin:
      AuthenticationMessenger::CorrectLoginMessage();
      is_login_ok_ = true;
      break;
    case ATM::AuthenticationStatus::kShortLogin:
      AuthenticationMessenger::LoginLengthStatus(
          AuthenticationMessenger::kShortLoginLength);
      break;
    case ATM::AuthenticationStatus::kLongLogin:
      AuthenticationMessenger::LoginLengthStatus(
          AuthenticationMessenger::kLongLoginLength);
      break;
    case ATM::AuthenticationStatus::kSpecialSymbols:
      AuthenticationMessenger::LoginContainSpecialSymbol();
      break;
    case ATM::AuthenticationStatus::kBeginWithSpace:
      AuthenticationMessenger::LoginContainIncorrectSpacePosition(
          AuthenticationMessenger::ContainSpaceSymbol::kBeginWithSpace);
      break;
    case ATM::AuthenticationStatus::kEndWithSpace:
      AuthenticationMessenger::LoginContainIncorrectSpacePosition(
          AuthenticationMessenger::ContainSpaceSymbol::kEndWithSpace);
      break;
    case ATM::AuthenticationStatus::kAdjacentSpaces:
      AuthenticationMessenger::LoginContainIncorrectSpacePosition(
          AuthenticationMessenger::ContainSpaceSymbol::kAdjecentSpaces);
      break;
    case ATM::AuthenticationStatus::kContainOnlyDigits:
      AuthenticationMessenger::LoginContainOnlyDigits();
      break;
    case ATM::AuthenticationStatus::kEmptyString:
      AuthenticationMessenger::LoginEmpty();
      break;
    default:
      break;
  }
}

void LogonHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
  switch (password_status_) {
    case ATM::AuthenticationStatus::kCorrectPassword:
      AuthenticationMessenger::CorrectPasswordMessage();
      is_password_ok_ = true;
      break;
    case ATM::AuthenticationStatus::kShortPassword:
      AuthenticationMessenger::PasswordLength(
          AuthenticationMessenger::kShortPasswordLength);
      break;
    case ATM::AuthenticationStatus::kLongPassword:
      AuthenticationMessenger::PasswordLength(
          AuthenticationMessenger::kLongPasswordLength);
      break;
    case ATM::AuthenticationStatus::kContainSpaceSymbol:
      AuthenticationMessenger::PasswordContainSpaceSymbol();
      break;
    case ATM::kEmptyString:
      AuthenticationMessenger::PasswordEmpty();
      break;
    default:
      break;
  }
  AuthenticationMessenger::AddEmptyLines(2);
}
