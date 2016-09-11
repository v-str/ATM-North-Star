#ifndef USER_CREDIT_H
#define USER_CREDIT_H

#include <iostream>

#include <string>
#include "account_info.h"
#include "identification_of_user.h"
#include "notice_about_error.h"
#include "system_utility.h"

#include "user_input.h"
#include "user_messanger.h"

#include "user_choice.h"

using std::cout;
using std::cin;

class UserCredit {
  using string = std::string;

 public:
  UserCredit();

  bool AlreadyHasACredit(AccountInfo &account_info) const;
  void RefuseToGrantAnotherCredit() const;

  bool ConsiderACredit(IdentificationOfUser &identification_of_user);

 private:
  double CalculateCredit(int sum, int amount_of_months);
  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);

  bool ConsiderACreditBasedOnCash(IdentificationOfUser &identification_of_user);
  bool GiveACredit(IdentificationOfUser &identification_of_user);

  bool MaxCreditCalculation(IdentificationOfUser &identification_of_user,
                            int maximal_sum_of_credit);

  bool IndividualCreditCalculation(IdentificationOfUser &identification_of_user,
                                   int maximal_sum_of_credit);

  bool EnrollACredit(IdentificationOfUser &identification_of_user,
                     double sum_of_credit, double pay_per_month);
  bool RepealACredit(IdentificationOfUser &identification_of_user);

  bool RefuseACredit(IdentificationOfUser &identification_of_user);
  bool ExitCreditMenu();

  void MonthToRepay(IdentificationOfUser &identification_of_user);
  int GetCreditMonths(IdentificationOfUser &identification_of_user);

  SystemUtility utility_;
  UserMessanger user_messanger_;
  UserInput user_input_;
  NoticeAboutError error_;
  UserChoice user_choice_;
};

#endif  // USER_CREDIT_H
