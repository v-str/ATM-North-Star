#ifndef ATM_MACHINE_H
#define ATM_MACHINE_H

#include <string>

#include <account_informator.h>
#include <atm_user.h>

class AtmMachine {
 public:
  void RegisterUser(const std::string& login, const std::string& password);

 private:
  AtmUser user_;
};

#endif  // ATM_MACHINE_H
