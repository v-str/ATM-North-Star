#include "data_validator.h"

#include <cmath>

double DataValidator::k_null_ = 0.0;

bool DataValidator::IsIntegerSum(double sum) {
  double integer_part = 0.0;
  double fractional_part = std::modf(sum, &integer_part);
  return fractional_part == k_null_;
}
