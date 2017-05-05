#ifndef ATM_h
#define ATM_h

#include <string>

#include <atm_user.h>

class Atm {
 public:
  void RegisterUser(const std::string& login, const std::string& password);

 private:
  AtmUser user_;
};

#endif  // ATM_h
