#ifndef DEMO_MESSANGER_H
#define DEMO_MESSANGER_H

#include <iostream>
#include <string>

#include "account_info.h"
#include "system_utility.h"

using std::cout;
using std::cin;

class UserMessanger {
  using string = std::string;

 public:
  UserMessanger();

  void WriteSymbolsNTimes(char symbol, int n) const;
  void ShowRegistrationScreen() const;

  void WriteUserInfo(const string &info_title, const string &value);

  void ShowAccountInfo(const AccountInfo &account_info);

  void ShowTransactionMenu();

  void ShowNotifyAboutCash();

  void ShowUserBalance(double balance);

//  void ShowUnacceptableWithdrawal(const AccountInfo &account_info,
//                                  int incorrect_sum);

  string SuggestToConfirmACredit();

  void ShowSumOfWithdrawal(int sum_of_cash) const;

  void ShowSuccessfulWithdrawal(int sum_of_cash, int sum_of_withdrawal);

  void ShowIncorrectPasswordMessage();

  void ShowStatement(int cash, string &spaces);

  void ShowIncorrectDataMessage();
  void ShowIncorrectMonthInput();
  void ShowNotifyAboutCredit();

  void ShowCreditConditions(int maximal_sum_of_credit);
  void ShowInfoAboutCredit(string &user_login, int max_sum);
  void ShowEnrollACredit();
  void ShowIndividualCreditInfo(string &user_login, int sum_of_credit);

  void ShowRefuseACredit(int sum_of_cash) const;
  void RefusToGrantAnotherCredit() const;

  void SuggestUserToExit() const;
  void WishAGoodDay() const;
  void ShowTransactionMenu() const;

 private:
  SystemUtility utility_;
};

#endif  // DEMO_MESSANGER_H
