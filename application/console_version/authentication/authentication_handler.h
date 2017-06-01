#ifndef AUTHENTICATION_HANLDER_H
#define AUTHENTICATION_HANLDER_H

#include <string>

#include <authentication_status.h>
#include <authenticator.h>

class AuthenticationHandler {
 public:
  void HandleAuthenticationData(const std::string login,
                                const std::string& password);

 private:
  void HandleLoginString(const std::string& login);
  void HandlePasswordString(const std::string& password);

  Authenticator authenticator_;
  ATM::AuthenticationStatus login_status_;
  ATM::AuthenticationStatus password_status_;
};

#endif  // AUTHENTICATION_HANLDER_H
