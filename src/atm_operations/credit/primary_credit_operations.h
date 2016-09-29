#ifndef PRIMARY_CREDIT_OPERATIONS_H
#define PRIMARY_CREDIT_OPERATIONS_H

#include <string>

#include "cash_operator.h"
#include "credit_messenger.h"
#include "notice_about_error.h"
#include "result_of_offer.h"
#include "secondary_credit_operations.h"
#include "system_utility.h"
#include "user_choice.h"
#include "user_identifier.h"
#include "user_input.h"

class PrimaryCreditOperations {
  using string = std::string;

  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool MaxCreditCalculation(CashOperator &cash_operator,
                            const string &user_login,
                            int maximal_sum_of_credit);

  bool IndividualCreditCalculation(CashOperator &cash_operator,
                                   const string &user_login,
                                   int maximal_sum_of_credit);

 private:
  double CalculateCredit(int sum_of_credit, int amount_of_months);

  NoticeAboutError error_operation_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  SecondaryCreditOperations secondary_credit_operation_;
  UserChoice user_choice_;
  UserInput user_input_;
  ResultOfOffer result_of_offer_;
};

#endif  // PRIMARY_CREDIT_OPERATIONS_H
