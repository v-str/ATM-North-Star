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
    default:
      break;
  }
}

void AuthenticationHandler::HandlePasswordString(const std::string& password) {
  password_status_ = authenticator_.InspectPasswordString(password);
}
