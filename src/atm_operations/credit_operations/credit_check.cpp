#include "credit_check.h"

int CreditCheck::GetResultOfUserCheck(const AtmUser& user) const {
  if (IsCreditExist(user)) {
    return state_.kCreditExist;
  } else if (!IsBalanceAppropriate(user)) {
    return state_.kInappropriateBalance;
  } else if (!IsCreditExist(user) && IsBalanceAppropriate(user)) {
    return state_.kPositiveCheck;
  }

  return state_.kInvalidCheck;
}

bool CreditCheck::IsBalanceAppropriate(const AtmUser& user) const {
  return (user.GetCash() >= state_.kAppropriateSumForCredit) ? true : false;
}

bool CreditCheck::IsCreditExist(const AtmUser& user) const {
  return (user.GetCredit() > state_.kNull) ? true : false;
}
