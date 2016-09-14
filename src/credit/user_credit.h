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
#include "primary_credit_operations.h"
#include "secondary_credit_operations.h"


using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  UserCredit();

  bool AlreadyHasACredit(UserIdentifier &user_identifier) const;
  void RefuseToGrantAnotherCredit() const;

  bool ConsiderACredit(UserIdentifier &user_identifier);
  //==========================================================================
 private:
  bool ConsiderACreditBasedOnCash(UserIdentifier &user_identifier);

  bool GiveACredit(UserIdentifier &user_identifier);

  bool MaxCreditCalculation(UserIdentifier &user_identifier, int maximal_sum_of_credit);
  bool IndividualCreditCalculation(UserIdentifier &user_identifier,
                                   int maximal_sum_of_credit);

  double CalculateCredit(int sum, int amount_of_months);


  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);



  bool EnrollACredit() const;
  bool RepealACredit() const;

  bool RefuseACredit(UserIdentifier &user_identifier);

  int GetAmountOfMonthToRepayACredit();

  int GetCreditMonths();

  SystemUtility utility_;
  NoticeAboutError error_;
  UserChoice user_choice_;

  UserInput user_input_;
  CreditMessanger credit_messenger_;

  PrimaryCreditOperations primary_credit_operations_;
  SecondaryCreditOperations secondary_credit_operation_;
};

#endif  // USER_CREDIT_H
