#ifndef LOGON_HANDLING_H
#define LOGON_HANDLING_H

#include <string>

#include <authentication_status.h>
#include <authenticator.h>

class LogonHandler {
 public:
  void HandleLogonData(const std::string login, const std::string& password);

  bool IsAuthenticationOk() const;

 private:
  void HandleLoginString(const std::string& login);
  void HandlePasswordString(const std::string& password);

  Authenticator authenticator_;
  ATM::AuthenticationStatus login_status_;
  ATM::AuthenticationStatus password_status_;

  bool is_login_ok_ = false;
  bool is_password_ok_ = false;
};

#endif  // LOGON_HANDLING_H
