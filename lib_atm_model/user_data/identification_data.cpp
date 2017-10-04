#include <identification_data.h>

IdentificationData::IdentificationData()
    : login_("user"), password_("password") {}

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

void IdentificationData::SetPasswordTooltip(
    const std::string& control_question) {
  password_tooltip_ = control_question;
}

std::string IdentificationData::Login() const { return login_; }

std::string IdentificationData::Password() const { return password_; }

std::string IdentificationData::PasswordTooltip() const {
  return password_tooltip_;
}
