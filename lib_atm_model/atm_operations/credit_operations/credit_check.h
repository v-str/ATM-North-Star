#ifndef CREDIT_CHECK_H
#define CREDIT_CHECK_H

#include "atm_user.h"
#include "check_state.h"

class CreditCheck {
 public:
  int GetResultOfUserCheck(const AtmUser& user) const;

 private:
  bool IsBalanceAppropriate(const AtmUser& user) const;
  bool IsCreditExist(const AtmUser& user) const;
};

#endif  // CREDIT_CHECK_H
