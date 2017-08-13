#ifndef LOGON_HANDLING_H
#define LOGON_HANDLING_H

#include <string>

#include <logon_inspector.h>
#include <logon_status.h>

class LogonHandler {
 public:
  void HandleLogonData(const std::string login, const std::string& password);

  bool IsAuthenticationOk() const;

 private:
  void HandleLoginString(const std::string& login);
  void HandlePasswordString(const std::string& password);

  LogonInspector authenticator_;
  ATM::LogonStatus login_status_;
  ATM::LogonStatus password_status_;

  bool is_login_ok_ = false;
  bool is_password_ok_ = false;
};

#endif  // LOGON_HANDLING_H
