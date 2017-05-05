#include "data_validator.h"

#include <cmath>

bool DataValidator::IsIntegerSum(double sum) {
  double integer_part = 0.0;
  double fractional_part = std::modf(sum, &integer_part);

  return fractional_part == 0.0;
}
