#include "data_validator.h"

#include <cmath>

int DataValidator::k_login_max_length_ = 35;
int DataValidator::k_login_min_length_ = 4;
double DataValidator::k_null_ = 0.0;

bool DataValidator::IsLengthRight(const std::string& login) {
  return login.length() >= k_login_min_length_ &&
         login.length() <= k_login_max_length_;
}

bool DataValidator::IsIntegerSum(double sum) {
  double integer_part = 0.0;
  double fractional_part = std::modf(sum, &integer_part);
  return fractional_part == k_null_;
}
