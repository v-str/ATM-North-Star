#ifndef IDENTIFICATION_OF_USER_H
#define IDENTIFICATION_OF_USER_H

#include <iostream>
#include <string>
#include "account_info.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_messenger.h"

using std::cin;
using std::cout;

class UserIdentifier {
  using string = std::string;

 public:
  UserIdentifier();

  void InitLogin(const string &login);
  void InitPassword(const string &password);
  void InitCash(int cash);
  void InitCredit(int credit);
  void InitMonthlyPayment(double monthly_payment);
  void InitAmountOfCreditMonth(int amount_credit_month);

  int AddCash(int sum);

  int DeductCashFromUser(int sum);
  int ReturnCash() const;
  int ReturnCredit() const;
  string ReturnLogin() const;
  string ReturnPassword() const;
  int ReturnAmountOfCreditMonth() const;

  int AssignACredit(int sum_of_credit);
  double AssignAMonthlyPayment(double pay_per_month);
  bool IsCreditAvailable();

  void GetLogin();
  void GetPassword();

  bool IsNormalLogin();
  bool IsNormalPass();

  void ShowAccountInformation();

  string GetPasswordFromUser();

 private:
  AccountInfo account_info_;
  NoticeAboutError error_message_;
  UserMessenger user_messanger_;
  SystemUtility utility_;
};

#endif  // IDENTIFICATION_OF_USER_H
