#include <identification_data.h>

IdentificationData::IdentificationData()
    : login_("user"), password_("password") {}

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

void IdentificationData::SetTooltip(const std::string& control_question) {
  tooltip_ = control_question;
}

std::string IdentificationData::Login() const { return login_; }

std::string IdentificationData::Password() const { return password_; }

std::string IdentificationData::Tooltip() const { return tooltip_; }
