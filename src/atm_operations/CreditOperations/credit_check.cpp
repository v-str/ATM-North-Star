#include "credit_check.h"

bool CreditCheck::IsCheckPositive(AtmUser& user) const {
  if (IsBalanceAppropriate(user) && !IsCreditExist(user)) {
    return true;
  } else {
    return false;
  }
}

bool CreditCheck::IsBalanceAppropriate(AtmUser& user) const {
  return (user.GetCash() >= kAppropriateSumForCredit) ? true : false;
}

bool CreditCheck::IsCreditExist(AtmUser& user) const {
  return (user.GetCredit() > kNull) ? true : false;
}
