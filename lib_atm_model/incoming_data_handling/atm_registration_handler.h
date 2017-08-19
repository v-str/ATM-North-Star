#ifndef ATM_REGISTRATION_HANDLER_H
#define ATM_REGISTRATION_HANDLER_H

#include <string>

#include <registration_inspector.h>
#include <registration_status.h>

class AtmRegistrationHandler {
 public:
  ATM::RegistrationStatus HandleLoginString(const std::string login);
  ATM::RegistrationStatus HandlePasswordString(const std::string password);

 private:
  RegistrationInspector registration_inpector_;

  bool is_login_correct_ = false;
  bool is_password_correct = false;
};

#endif  // ATM_REGISTRATION_HANDLER_H
