#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

#include <iostream>
#include <string>

#include "cash_operator.h"
#include "refill_messenger.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

using std::cout;
using std::cin;

class UserMessenger {
  using string = std::string;

 public:
  UserMessenger();

  void ShowRegistrationScreen() const;

  void ShowTransactionMenu();

  void ShowNotifyAboutCash();

  void ShowIncorrectDataMessage();
  void ShowIncorrectMonthInput();

  void WishAGoodDay() const;
  void ShowTransactionMenu() const;

  bool SuggestUserToExit();
  bool ShowAccountInformation(UserIdentifier &user_identifier,
                              CashOperator &cash_operator);

  void ShowInitialLoginText();
  void ShowInitialPasswordText();

 private:
  SystemUtility utility_;
  RefillMessenger refill_messenger_;
  UserInput user_input_;
};

#endif  // USER_MESSANGER_H
