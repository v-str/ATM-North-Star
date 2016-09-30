#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "notice_about_error.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

typedef int credit;

class SecondaryCreditOperations {
 public:
  credit GetCreditVariant(const credit maximal_sum_of_credit,
                          const credit credit_variant);

  credit GetCreditMonth();

 private:
  credit GetSumOfCreditFromUser(const credit maximal_sum_of_credit);
  bool IsMonthCorrect(credit months);

  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  NoticeAboutError error_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
