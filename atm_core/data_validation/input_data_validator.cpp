#include "input_data_validator.h"

#include <cmath>

bool InputDataValidator::IsLoginLengthRight(const std::string& login) {
  return login.length() >= k_login_min_length_ &&
         login.length() <= k_login_max_length_;
}

bool InputDataValidator::IsPasswordLengthRight(const std::string& login) {
  return login.length() == k_password_length_;
}

bool InputDataValidator::IsRefillingCorrect(int refill_sum) {
  if (IsIntegerValue(refill_sum)) {
    return refill_sum >= k_min_refill_sum_ && refill_sum <= k_max_refill_sum_;
  }
  return false;
}

bool InputDataValidator::IsIntegerValue(double value) {
  double integer_part = k_null_;
  double fractional_part = std::modf(value, &integer_part);
  return fractional_part == k_null_;
}
