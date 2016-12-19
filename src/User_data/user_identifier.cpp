#include "user_identifier.h"

void UserIdentifier::SetLogin(const string &login) { login_ = login; }

void UserIdentifier::SetPassword(const UserIdentifier::string &password) {
  password_ = password;
}

UserIdentifier::string UserIdentifier::GetLogin() const { return login_; }

UserIdentifier::string UserIdentifier::GetPassword() const { return password_; }

bool UserIdentifier::IsNormalLogin() {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool UserIdentifier::IsNormalPass() {
  return password_.length() == kMaxLenghtOfPassword;
}