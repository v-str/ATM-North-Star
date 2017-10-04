#ifndef ATM_REGISTRATION_HANDLER_H
#define ATM_REGISTRATION_HANDLER_H

#include <string>

#include <atm_registration_status.h>
#include <registration_inspector.h>

class AtmRegistrationHandler {
 public:
  ATM::RegistrationStatus HandleLoginString(const std::string& login);
  ATM::RegistrationStatus HandlePasswordString(const std::string& password);
  void HandlePasswordTooltip(const std::string& password_tooltip);

  bool IsRegistrationDataCorrect() const;
  bool PasswordTooltipCondition() const;

 private:
  void CheckLoginString();
  void CheckPasswodString();

  RegistrationInspector registration_inpector_;

  ATM::RegistrationStatus login_status_;
  ATM::RegistrationStatus password_status_;

  bool is_login_correct_ = false;
  bool is_password_correct_ = false;
  bool is_password_tooltip_correct_ = false;
};

#endif  // ATM_REGISTRATION_HANDLER_H
