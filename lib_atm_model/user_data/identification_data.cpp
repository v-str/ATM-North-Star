#include <identification_data.h>

IdentificationData::IdentificationData()
    : login_("user"), password_("password") {}

void IdentificationData::SetLogin(const std::string& login) { login_ = login; }

void IdentificationData::SetPassword(const std::string& password) {
  password_ = password;
}

void IdentificationData::SetControlQuestion(
    const std::string& control_question) {
  control_question_ = control_question;
}

void IdentificationData::SetControlAnswer(const std::string& contol_answer) {
  control_answer_ = contol_answer;
}

std::string IdentificationData::Login() const { return login_; }

std::string IdentificationData::Password() const { return password_; }

std::string IdentificationData::ControlQuestion() const {
  return control_question_;
}

std::string IdentificationData::ControlAnswer() const {
  return control_answer_;
}
