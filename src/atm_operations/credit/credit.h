#ifndef CREDIT_H
#define CREDIT_H

#include <string>

#include "cash_operator.h"
#include "credit_offer.h"
#include "secondary_credit_operations.h"

class Credit {
  using string = std::string;

 public:
  void GiveCreditByMode(CashOperator &cash_operator, const string &user_login,
                        int maximal_sum_of_credit, int credit_mode);

 private:
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

  SecondaryCreditOperations secondary_credit_operation_;
  CreditOffer credit_offer_;
};

#endif  // CREDIT_H
