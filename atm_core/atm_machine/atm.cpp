#include "atm.h"

#include <user_registrator.h>

void Atm::RegisterUser(const std::string& login,
                              const std::string& password) {
  UserRegistrator::RegisterUser(&user_, login, password);
}
