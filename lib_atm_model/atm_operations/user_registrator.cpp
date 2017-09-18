#include <user_registrator.h>

#include <atm_user.h>

void UserRegistrator::RegisterUser(AtmUser* user, const std::string& login,
                                   const std::string& password) {
  AssignLogin(user, login);
  AssignPassword(user, password);
}

void UserRegistrator::AssignLogin(AtmUser* user, const std::string& login) {
  user->SetLogin(login);
}

void UserRegistrator::AssignPassword(AtmUser* user,
                                     const std::string& password) {
  user->SetPassword(password);
}
