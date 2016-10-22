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

  void ShowMainMenu();

  void ShowNotifyAboutCash();

  void ShowIncorrectDataMessage();
  void ShowIncorrectMonthInput();

  void WishAGoodDay() const;
  void ShowMainMenu() const;

  void SuggestUserToExit() const;

  void ShowSuggestionAboutExit() const;
  void ShowIncorrectSumInput() const;

  void ShowIncorrectData() const;

  void ShowIncorrectRegisterData() const;

 private:
  SystemUtility utility_;
};

#endif  // USER_MESSANGER_H
