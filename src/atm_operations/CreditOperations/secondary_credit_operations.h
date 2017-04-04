#ifndef SECONDARY_CREDIT_OPERATIONS_H
#define SECONDARY_CREDIT_OPERATIONS_H

#include "credit_messenger.h"
#include "user_input.h"

class SecondaryCreditOperations {
 public:
  int GetAmountCreditByMode(int maximal_sum_of_credit, int credit_mode) const;

  int GetAmountCreditMonths() const;

  double CalculateMonthlyPayment(int sum_of_credit,
                                 int amount_of_credit_months) const;

 private:
  int GetCreditSumFromUser(int maximal_sum_of_credit) const;

  const int kInvalidValue = -1;
  const int kUserCredit = 1;
  const int kRatePerYear = 14;
  const int kFullRate = 100;
  const int kOneYear = 12;
  const int kMaximalCreditTerm = 61;

  bool IsMonthCorrect(int months) const;

  UserInput user_input_;
  CreditMessanger credit_messenger_;
};

#endif  // SECONDARY_CREDIT_OPERATIONS_H
