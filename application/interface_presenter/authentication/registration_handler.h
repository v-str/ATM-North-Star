#ifndef REGISTRATION_HANDLER_H
#define REGISTRATION_HANDLER_H

#include <string>

#include <logon_status.h>
#include <registration_inspector.h>

class RegistrationHandler {
 public:
  void HandleRegistrationData(const std::string login,
                              const std::string& password);

  bool IsAuthenticationOk() const;

 private:
  void HandleLoginString(const std::string& login);
  void HandlePasswordString(const std::string& password);

  RegistrationInspector authenticator_;
  ATM::LogonStatus login_status_;
  ATM::LogonStatus password_status_;

  bool is_login_ok_ = false;
  bool is_password_ok_ = false;
};

#endif  // REGISTRATION_HANDLER_H
