#ifndef CREDIT_CHECK_H
#define CREDIT_CHECK_H

#include "atm_user.h"

class CreditCheck {
 public:
  bool IsCheckPositive(AtmUser& user) const;

 private:
  bool IsBalanceAppropriate(AtmUser& user) const;
  bool IsCreditExist(AtmUser& user) const;

  const int kAppropriateSumForCredit = 1000;
  const int kNull = 0;
};

#endif  // CREDIT_CHECK_H
