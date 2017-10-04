#ifndef ACCOUNT_INFORMATOR_H
#define ACCOUNT_INFORMATOR_H

#include <string>

class AtmUser;

class AccountInformator {
 public:
  static void UpdataUserData(const AtmUser& user);

  static std::string Login();
  static std::string Cash();
  static std::string PasswordTooltip();

 private:
  static std::string login_;
  static std::string cash_;
  static std::string password_tooltip_;
};

#endif  // ACCOUNT_INFORMATOR_H
