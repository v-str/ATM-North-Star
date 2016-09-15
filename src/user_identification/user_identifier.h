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

  void SetLogin(const string &login);
  void SetPassword(const string &password);
  void SetCash(int cash);
  void SetCredit(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetAmountOfCreditMonth(int amount_credit_month);


  int AddCash(int sum);
  int DeductCashFromUser(int sum);
  int Cash() const;
  int Credit() const;
  int AmountOfCreditMonth() const;
  int AssignACredit(int sum_of_credit);
  double AssignAMonthlyPayment(double pay_per_month);
  bool IsCreditAvailable();


  string ReturnLogin() const;
  string ReturnPassword() const;

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
