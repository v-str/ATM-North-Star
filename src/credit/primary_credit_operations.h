#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include <string>

#include "credit_messenger.h"
#include "notice_about_error.h"
#include "secondary_credit_operations.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_choice.h"

class PrimaryCreditOperations {
  using string = std::string;

 public:
  bool MaxCreditCalculation(UserIdentifier &user_identifier,
                            int maximal_sum_of_credit);

 private:
  double CalculateCredit(const int sum, const int amount_of_months);

  NoticeAboutError error_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserChoice user_choice_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H
