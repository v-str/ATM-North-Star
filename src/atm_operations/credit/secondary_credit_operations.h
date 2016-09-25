#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  bool EnrollACredit() const;

  bool RepealACredit() const;

  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);

  int GetMonth();

 private:
  bool IsMonthNotCorrect(int months);

  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
