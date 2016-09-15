#ifndef IDENTIFICATION_OF_USER_H
#define IDENTIFICATION_OF_USER_H

#include <iostream>
#include <string>
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_messenger.h"

using std::cin;
using std::cout;

class UserIdentifier {
  using string = std::string;

 public:
  void ShowLogin(const string &login);
  void ShowPassword(const string &password);

  void ShowLogin();
  void ShowPassword();

  string GetLogin() const;
  string GetPassword() const;

  bool IsNormalLogin();
  bool IsNormalPass();

  string GetPasswordFromUser();

 private:
  string login_ = "no_name";
  string password_ = "0000";

  int cash_ = 0;
  int credit_ = 0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;

  NoticeAboutError error_message_;
  UserMessenger user_messanger_;
  SystemUtility utility_;
};

#endif  // IDENTIFICATION_OF_USER_H
