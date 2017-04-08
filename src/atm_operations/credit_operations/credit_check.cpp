#include "credit_check.h"

bool CreditCheck::IsCheckPositive(const AtmUser& user) const {
  if (IsBalanceAppropriate(user) && !IsCreditExist(user)) {
    return true;
  } else {
    return false;
  }
}

bool CreditCheck::IsBalanceAppropriate(const AtmUser& user) const {
  return (user.GetCash() >= AppropriateSumForCredit) ? true : false;
}

bool CreditCheck::IsCreditExist(const AtmUser& user) const {
  return (user.GetCredit() > kNull) ? true : false;
}
