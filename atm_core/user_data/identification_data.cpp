#include "identification_data.h"

IdentificationData::IdentificationData()
    : login_("user"), password_("password") {}

IdentificationData::IdentificationData(
    const IdentificationData& identification_data) {
  login_ = identification_data.Login();
  password_ = identification_data.Password();
}

IdentificationData& IdentificationData::operator=(
    const IdentificationData& identification_data) {
  login_ = identification_data.Login();
  password_ = identification_data.Password();

  return *this;
}

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

std::string IdentificationData::Login() const { return login_; }

std::string IdentificationData::Password() const { return password_; }
