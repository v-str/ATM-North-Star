#ifndef INPUT_DATA_VALIDATOR_H
#define INPUT_DATA_VALIDATOR_H

#include <string>

class InputDataValidator {
 public:
  static bool IsLoginLengthRight(const std::string& login);
  static bool IsPasswordLengthRight(const std::string& login);
  static bool IsIntegerValue(double value);

 private:
  static constexpr int k_login_max_length_ = 35;
  static constexpr int k_login_min_length_ = 4;

  static constexpr int k_password_length_ = 4;

  static constexpr double k_null_ = 0.0;
};
// int InputDataValidator::k_login_max_length_ = 35;
// int InputDataValidator::k_login_min_length_ = 4;
// int InputDataValidator::k_password_length_ = 4;
// double InputDataValidator::k_null_ = 0.0;
#endif  // INPUT_DATA_VALIDATOR_H
