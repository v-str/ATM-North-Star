#ifndef USER_REGISTRATOR_H
#define USER_REGISTRATOR_H

#include <atm_user.h>

class UserRegistrator {
 public:
  static void Register(AtmUser* user,
                       const std::string& login,
                       const std::string& password);

 private:
  static void AssignLogin(AtmUser* user, const std::string& login);
  static void AssignPassword(AtmUser* user, const std::string& password);
};

#endif  // USER_REGISTRATOR_H
