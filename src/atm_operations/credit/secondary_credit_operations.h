#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "notifier.h"
#include "system_utility.h"
#include "user_identifier.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  int GetAmountCreditByMode(const int maximal_sum_of_credit, const int credit_mode);

  int GetAmountCreditMonths();

  double CalculateMonthlyPayment(const int sum_of_credit,
                                 const int amount_of_credit_months) const;

 private:
  int GetSumOfCreditFromUser(const int maximal_sum_of_credit);
  bool IsMonthCorrect(int months);

  UserInput user_input_;
  SystemUtility utility_;
  CreditMessanger credit_messenger_;
  Notifier error_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
