#include <user_registrator.h>

#include <atm_user.h>

void UserRegistrator::RegisterUser(AtmUser* user,
                                   const std::string& login,
                                   const std::string& password,
                                   const std::string& password_tooltip) {
  AssignLogin(user, login);
  AssignPassword(user, password);
  AssignPasswordTooltip(user, password_tooltip);
}

void UserRegistrator::AssignLogin(AtmUser* user, const std::string& login) {
  user->SetLogin(login);
}

void UserRegistrator::AssignPassword(AtmUser* user,
                                     const std::string& password) {
  user->SetPassword(password);
}

void UserRegistrator::AssignPasswordTooltip(
    AtmUser* user, const std::string& password_tooltip) {
  user->SetPasswordTooltip(password_tooltip);
}
