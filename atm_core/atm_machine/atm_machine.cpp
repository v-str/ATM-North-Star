#include "atm_machine.h"

#include <user_registrator.h>

void AtmMachine::RegisterUser(const std::string& login,
                              const std::string& password) {
  UserRegistrator::Register(&user_, login, password);
}
