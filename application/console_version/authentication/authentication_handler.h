#ifndef AUTHENTICATION_HANLDER_H
#define AUTHENTICATION_HANLDER_H

#include <string>

#include <authentication_status.h>

class AuthenticationHandler {
 public:
  void HandleAuthenticationData(const std::string login,
                                const std::string& password);


};

#endif  // AUTHENTICATION_HANLDER_H
