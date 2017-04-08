#ifndef CREDIT_CHECK_H
#define CREDIT_CHECK_H

#include "atm_user.h"

class CreditCheck {
 public:
  bool IsCheckPositive(const AtmUser& user) const;

 private:
  bool IsBalanceAppropriate(const AtmUser& user) const;
  bool IsCreditExist(const AtmUser& user) const;

  const int AppropriateSumForCredit = 1000;
  const int kNull = 0;
};

#endif  // CREDIT_CHECK_H
