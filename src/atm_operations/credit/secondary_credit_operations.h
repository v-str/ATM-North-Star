#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  int CalculateCreditSum(const int maximal_sum_of_credit,
                         const int credit_variant);

  int GetMonth();

 private:
  int GetSumOfCreditFromUser(int maximal_sum_of_credit);
  bool IsMonthCorrect(int months);

  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
