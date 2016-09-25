#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"
#include "notice_about_error.h"

class SecondaryCreditOperations {
 public:
  bool EnrollACredit() const;

  bool RepealACredit() const;

  int GetAmountOfCreditMonthsFromUser();

  int GetIndividualSumOfCreditFromUser(int maximal_sum_of_credit);


 private:
  int GetMonth();

  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
