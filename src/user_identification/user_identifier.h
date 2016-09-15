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
  void SetCash(int cash);
  void SetCredit(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetAmountOfCreditMonth(int amount_credit_month);

  void SetLogin(const string &login);
  void SetPassword(const string &password);

  void SetLogin();
  void SetPassword();

  int GetCash() const;
  int GetCredit() const;
  int GetAmountOfCreditMonth() const;
  int GetAssignACredit(int sum_of_credit);

  string GetLogin() const;
  string GetPassword() const;

  double AssignAMonthlyPayment(double pay_per_month);

  bool IsCreditAvailable();

  int WithdrawCashFromUser(int amount);

  bool IsNormalLogin();
  bool IsNormalPass();

  void ShowAccountInformation();

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
