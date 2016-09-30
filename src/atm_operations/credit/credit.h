#ifndef CREDIT_H
#define CREDIT_H

#include <string>

#include "cash_operator.h"
#include "credit_offer.h"
#include "secondary_credit_operations.h"

class Credit {
  using string = std::string;

  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

 public:
  bool GiveCreditByMode(CashOperator &cash_operator, const string &user_login,
                     const int maximal_sum_of_credit, const int credit_mode);

 private:
  int AmountOfCreditByMode(const int maximal_sum_of_credit,
                         const int credit_mode);

  int AmountOfCreditMonth(CashOperator &cash_operator);

  SecondaryCreditOperations secondary_credit_operation_;
  CreditOffer credit_offer_;
};

#endif  // CREDIT_H
