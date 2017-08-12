#include "identification_data.h"

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

std::string IdentificationData::Login() const { return login_; }

std::string IdentificationData::Password() const { return password_; }

bool IdentificationData::IsNormalLogin() const {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool IdentificationData::IsNormalPass() const {
  return password_.length() == kMaxLenghtOfPassword;
}
