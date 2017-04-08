#ifndef CREDIT_CHECK_H
#define CREDIT_CHECK_H

#include "atm_user.h"

class CreditCheck {
 public:
  int GetResultOfUserCheck(const AtmUser& user) const;

 private:
  bool IsBalanceAppropriate(const AtmUser& user) const;
  bool IsCreditExist(const AtmUser& user) const;

  const int kAppropriateSumForCredit = 1000;
  const int kNull = 0;

  const int kPositiveCheck = 0;
  const int kCreditExist = 1;
  const int kInappropriateBalance = 2;
};

#endif  // CREDIT_CHECK_H
