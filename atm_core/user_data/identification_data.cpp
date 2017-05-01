#include "identification_data.h"

IdentificationData::IdentificationData()
    : login_("user"), password_("password") {}

IdentificationData::IdentificationData(const std::string& login,
                                       const std::string& password)
    : login_(login), password_(password) {}

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}
