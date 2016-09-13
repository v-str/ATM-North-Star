#ifndef IDENTIFICATION_OF_USER_H
#define IDENTIFICATION_OF_USER_H

#include <iostream>
#include <string>
#include "account_info.h"
#include "system_utility.h"
#include "user_messenger.h"
#include "notice_about_error.h"

using std::cin;
using std::cout;

class UserIdentificator {
  using string = std::string;

 public:
  UserIdentificator();
  UserIdentificator(const string &login);

  void GetLogin();
  void GetPassword();

  bool IsNormalLogin();
  bool IsNormalPass();

  void ShowAccountInformation();
  void NoticeAboutSuccessfulRegistration();

  void NoticeAboutIncorrectLogin() const;
  void NoticeAboutIncorrectPassword() const;

  string GetPasswordFromUser();


  AccountInfo account_info_;

 private:
  UserMessenger user_messanger_;
  SystemUtility utility_;
  NoticeAboutError error_;
};

#endif  // IDENTIFICATION_OF_USER_H
