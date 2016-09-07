#ifndef DEMO_MESSANGER_H
#define DEMO_MESSANGER_H

#include <iostream>
#include <string>

#include "system_utility.h"
#include "user_parameters.h"

using std::cout;
using std::cin;

class UserMessanger {
  using string = std::string;

 public:
  UserMessanger();

  void WriteSymbolsNTimes(char symbol, int n) const;
  void ShowRegistrationScreen();
  void ShowIncorrectLoginMessage();
  void ShowIncorrectPasswordMessage();

  void WriteUserInfo(const string &info_title, const string &value);

  void ShowAccountInfo(const AccountInfo &account_info);

  void ShowTransactionMenu();

  void ShowNotifyAboutCash();

  void ShowUserBalance(double &balance);
  void ShowIncorrectSum();

 private:
  SystemUtility utility_;
};

#endif  // DEMO_MESSANGER_H
