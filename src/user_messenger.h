#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

#include <iostream>
#include <string>

#include "cash_operator.h"
#include "system_utility.h"
#include "user_identifier.h"

using std::cout;
using std::cin;

class UserMessenger {
  using string = std::string;

 public:
  UserMessenger();

  void ShowRegistrationScreen() const;

  void WriteUserInfo(const string &info_title, const string &value);

  void ShowTransactionMenu();

  void ShowNotifyAboutCash();

  void ShowUserBalance(double balance);

  void ShowIncorrectDataMessage();
  void ShowIncorrectMonthInput();

  void SuggestUserToExit() const;
  void WishAGoodDay() const;
  void ShowTransactionMenu() const;

  void ShowAccountInformation(UserIdentifier &user_identifier,
                              CashOperator &cash_operator);

  void ShowInitialLoginText();
  void ShowInitialPasswordText();

 private:
  SystemUtility utility_;
};

#endif  // USER_MESSANGER_H
