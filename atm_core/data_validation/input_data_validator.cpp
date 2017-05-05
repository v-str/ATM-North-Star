#include "input_data_validator.h"

#include <cmath>

int InputDataValidator::k_login_max_length_ = 35;
int InputDataValidator::k_login_min_length_ = 4;
int InputDataValidator::k_password_length_ = 4;
double InputDataValidator::k_null_ = 0.0;

bool InputDataValidator::IsLoginLengthRight(const std::string& login) {
  return login.length() >= k_login_min_length_ &&
         login.length() <= k_login_max_length_;
}

bool InputDataValidator::IsPasswordLengthRight(const std::string& login) {
  return login.length() == k_password_length_;
}

bool InputDataValidator::IsIntegerValue(double value) {
  double integer_part = k_null_;
  double fractional_part = std::modf(value, &integer_part);
  return fractional_part == k_null_;
}
