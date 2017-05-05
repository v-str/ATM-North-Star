#ifndef DATA_VALIDATOR_H
#define DATA_VALIDATOR_H

#include <string>

class DataValidator {
 public:
  static bool IsLengthRight(const std::string& login);
  static bool IsIntegerSum(double sum);

 private:
  static int k_login_max_length_;
  static int k_login_min_length_;
  static double k_null_;
};

#endif  // DATA_VALIDATOR_H
