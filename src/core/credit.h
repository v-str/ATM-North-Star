#ifndef CREDIT_H
#define CREDIT_H

#include "user_data/atm_user.h"
#include "credit_offer.h"
#include "secondary_credit_operations.h"

#include <string>

class Credit {
  using string = std::string;

 public:
  void GiveCreditByMode(AtmUser *atm_user, const string &user_login,
                        int maximal_sum_of_credit, int credit_mode) const;

 private:
  enum CreditSolution { kEnroll = 1, kRepeal, kExit };

  SecondaryCreditOperations secondary_credit_operation_;
  CreditOffer credit_offer_;
};

#endif  // CREDIT_H
