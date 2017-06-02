#include <authentication_handler.h>

#include <authentication_messenger.h>

void AuthenticationHandler::HandleAuthenticationData(
    const std::string login, const std::string& password) {
  HandleLoginString(login);
  HandlePasswordString(password);
}

void AuthenticationHandler::HandleLoginString(const std::string& login) {
  login_status_ = authenticator_.InspectLoginString(login);
  switch (login_status_) {
    case ATM::AuthenticationStatus::kShortLogin:
      AuthenticationMessenger::LoginLength(
          AuthenticationMessenger::kShortLoginLength);
      break;
    case ATM::AuthenticationStatus::kLongLogin:
      AuthenticationMessenger::LoginLength(
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

void AuthenticationHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
}
