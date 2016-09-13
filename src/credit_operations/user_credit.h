#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "account_info.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identificator.h"
#include "user_input.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  UserCredit();

  bool AlreadyHasACredit(AccountInfo &account_info) const;
  void RefuseToGrantAnotherCredit() const;

  bool ConsiderACredit(UserIdentificator &identification_of_user);
  //==========================================================================
 private:
  double CalculateCredit(int sum, int amount_of_months);
  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);

  bool ConsiderACreditBasedOnCash(UserIdentificator &identification_of_user);
  bool GiveACredit(UserIdentificator &identification_of_user);

  bool MaxCreditCalculation(UserIdentificator &identification_of_user,
                            int maximal_sum_of_credit);

  bool IndividualCreditCalculation(UserIdentificator &identification_of_user,
                                   int maximal_sum_of_credit);

  bool EnrollACredit(UserIdentificator &identification_of_user,
                     double sum_of_credit, double pay_per_month);
  bool RepealACredit(UserIdentificator &identification_of_user);

  bool RefuseACredit(UserIdentificator &identification_of_user);
  bool ExitCreditMenu();

  void MonthToRepay(UserIdentificator &identification_of_user);
  int GetCreditMonths(UserIdentificator &identification_of_user);

  SystemUtility utility_;
  UserInput user_input_;
  NoticeAboutError error_;
  UserChoice user_choice_;
  CreditMessanger credit_messenger_;
};

#endif  // USER_CREDIT_H
