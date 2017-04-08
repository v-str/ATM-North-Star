#include "credit_check.h"

int CreditCheck::GetResultOfUserCheck(const AtmUser& user) const {
  if (IsCreditExist(user)) {
    return kCreditExist;
  } else if (!IsBalanceAppropriate(user)) {
    return kInappropriateBalance;
  }

  return kPositiveCheck;
}

bool CreditCheck::IsBalanceAppropriate(const AtmUser& user) const {
  return (user.GetCash() >= kAppropriateSumForCredit) ? true : false;
}

bool CreditCheck::IsCreditExist(const AtmUser& user) const {
  return (user.GetCredit() > kNull) ? true : false;
}
