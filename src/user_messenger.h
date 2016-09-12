#ifndef DEMO_MESSANGER_H
#define DEMO_MESSANGER_H

#include <iostream>
#include <string>

#include "account_info.h"
#include "system_utility.h"

using std::cout;
using std::cin;

class UserMessenger {
  using string = std::string;

 public:
  UserMessenger();

  void WriteSymbolsNTimes(char symbol, int n) const;
  void ShowRegistrationScreen() const;

  void WriteUserInfo(const string &info_title, const string &value);

  void ShowAccountInfo(const AccountInfo &account_info);

  void ShowTransactionMenu();

  void ShowNotifyAboutCash();

  void ShowUserBalance(double balance);

  void ShowSumOfWithdrawal(int sum_of_cash) const;

  void ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal);

  void ShowIncorrectPasswordMessage();

  void ShowStatement(int cash, string &spaces);

  void ShowIncorrectDataMessage();
  void ShowIncorrectMonthInput();

  void SuggestUserToExit() const;
  void WishAGoodDay() const;
  void ShowTransactionMenu() const;

 private:
  SystemUtility utility_;
};

#endif  // DEMO_MESSANGER_H
