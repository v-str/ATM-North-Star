#include <cash_operation_validator.h>

#include <cmath>

bool CashOperationValidator::IsRefillingCorrect(int refill_sum) {
  bool lower_refill_bound = refill_sum >= kMinimalRefillSum;
  bool upper_refill_bound = refill_sum <= kMaximalRefillSum;

  return lower_refill_bound && upper_refill_bound;
}

bool CashOperationValidator::IsWithdrawalCorrect(int withdrawal_sum) {
  bool lower_withdrawal_bound = withdrawal_sum >= kMinimalWithdrawalSum;
  bool upper_withdrawal_bound = withdrawal_sum <= kMaximalWithdrawalSum;

  return lower_withdrawal_bound && upper_withdrawal_bound;
}
