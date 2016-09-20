#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include <string>

#include "cash_operator.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "secondary_credit_operations.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identifier.h"

class PrimaryCreditOperations {
  using string = std::string;

 public:
  bool MaxCreditCalculation(CashOperator &cash_operator,
                            const string &user_login,
                            int maximal_sum_of_credit);

  bool IndividualCreditCalculation(CashOperator &cash_operator,
                                   const string &user_login,
                                   int maximal_sum_of_credit);

 private:
  double CalculateCredit(int sum, int amount_of_months);

  NoticeAboutError error_operation_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserChoice user_choice_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H
