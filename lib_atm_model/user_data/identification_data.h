#ifndef IDENTIFICATION_DATA_H
#define IDENTIFICATION_DATA_H

#include <string>

class IdentificationData {
 public:
  IdentificationData();

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);
  void SetPasswordTooltip(const std::string& control_question);

  std::string Login() const;
  std::string Password() const;
  std::string PasswordTooltip() const;

 private:
  std::string login_;
  std::string password_;
  std::string password_tooltip_;
};

#endif  // IDENTIFICATION_DATA_H
