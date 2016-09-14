#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "account_info.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identifier.h"
#include "user_input.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  UserCredit();

  bool AlreadyHasACredit() const;
  void RefuseToGrantAnotherCredit() const;

  bool ConsiderACredit(UserIdentifier &user_identifier);
  //==========================================================================
 private:
  bool ConsiderACreditBasedOnCash(UserIdentifier &user_identifier);

  bool GiveACredit(UserIdentifier &user_identifier);

  double CalculateCredit(int sum, int amount_of_months);

  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);

  bool MaxCreditCalculation(UserIdentifier &user_identifier,
                            int maximal_sum_of_credit);

  bool IndividualCreditCalculation(UserIdentifier &user_identifier,
                                   int maximal_sum_of_credit);

  bool EnrollACredit(UserIdentifier &user_identifier, double sum_of_credit,
                     double pay_per_month);
  bool RepealACredit(UserIdentifier &user_identifier);

  bool RefuseACredit(UserIdentifier &user_identifier);

  bool ExitCreditMenu();

  void MonthToRepay(UserIdentifier &user_identifier);

  int GetCreditMonths(UserIdentifier &user_identifier);

  SystemUtility utility_;
  UserInput user_input_;
  NoticeAboutError error_;
  UserChoice user_choice_;
  CreditMessanger credit_messenger_;
  UserIdentifier user_identifier;
};

#endif  // USER_CREDIT_H
