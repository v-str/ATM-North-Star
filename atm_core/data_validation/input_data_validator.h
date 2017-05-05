#ifndef INPUT_DATA_VALIDATOR_H
#define INPUT_DATA_VALIDATOR_H

#include <string>

class InputDataValidator {
 public:
  static bool IsLoginLengthRight(const std::string& login);
  static bool IsPasswordLengthRight(const std::string& login);
  static bool IsIntegerValue(double value);

 private:
  static int k_login_max_length_;
  static int k_login_min_length_;

  static int k_password_length_;

  static double k_null_;
};

#endif  // INPUT_DATA_VALIDATOR_H
