#include "identification_data.h"

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

std::string IdentificationData::GetLogin() const { return login_; }

std::string IdentificationData::GetPassword() const { return password_; }

bool IdentificationData::IsNormalLogin() {
  return !login_.empty() && login_.length() < kMaxLenghtOfLogin;
}

bool IdentificationData::IsNormalPass() {
  return password_.length() == kMaxLenghtOfPassword;
}
