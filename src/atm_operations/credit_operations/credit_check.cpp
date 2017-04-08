#include "credit_check.h"

bool CreditCheck::IsCheckPositive(const AtmUser& user) const {
  return (IsBalanceAppropriate(user) && !IsCreditExist(user)) ? true : false;
}

bool CreditCheck::IsBalanceAppropriate(const AtmUser& user) const {
  return (user.GetCash() >= AppropriateSumForCredit) ? true : false;
}

bool CreditCheck::IsCreditExist(const AtmUser& user) const {
  return (user.GetCredit() > kNull) ? true : false;
}
