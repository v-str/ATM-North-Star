#include "input_data_validator.h"

#include <cmath>

bool InputDataValidator::IsPasswordLengthCorrect(const std::string& login) {
  return login.length() == k_password_length_;
}

bool InputDataValidator::IsRefillingCorrect(int refill_sum) {
  if (IsIntegerValue(refill_sum)) {
    return refill_sum >= k_min_refill_sum_ && refill_sum <= k_max_refill_sum_;
  }
  return false;
}

bool InputDataValidator::IsWithdrawalCorrect(int withdrawal_sum) {
  if (IsIntegerValue(withdrawal_sum)) {
    return withdrawal_sum >= k_min_withdrawal_sum_ &&
           withdrawal_sum <= k_max_withdrawal_sum_;
  }
  return false;
}

bool InputDataValidator::IsIntegerValue(double value) {
  double integer_part = k_null_;
  double fractional_part = std::modf(value, &integer_part);
  return fractional_part == k_null_;
}
