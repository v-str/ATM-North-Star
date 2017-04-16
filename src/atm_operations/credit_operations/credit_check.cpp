#include "credit_check.h"

int CreditCheck::GetResultOfUserCheck(const AtmUser& user) const {
  if (IsCreditExist(user)) {
    return CheckState::kCreditExist;
  } else if (!IsBalanceAppropriate(user)) {
    return CheckState::kInappropriateBalance;
  } else if (!IsCreditExist(user) && IsBalanceAppropriate(user)) {
    return CheckState::kPositiveCheck;
  }

  return CheckState::kInvalidCheck;
}

bool CreditCheck::IsBalanceAppropriate(const AtmUser& user) const {
  return user.GetCash() >= CheckState::kAppropriateSumForCredit;
}

bool CreditCheck::IsCreditExist(const AtmUser& user) const {
  return user.GetCredit() > CheckState::kNull;
}
