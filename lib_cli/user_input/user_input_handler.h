#ifndef USER_INPUT_HANDLER_H
#define USER_INPUT_HANDLER_H

#include <string>

class UserInputHandler {
 public:
  int GetDigitInputFromUser();
  double GetDoubleDigitFromUser();

  std::string GetStringInputFromUser();

 private:
  bool IsContainOnlyDigits();
  int GetDigitsFromString();

  bool IsConvertableToDouble();
  double GetDoubleDigitsFromString();

  const int kInvalidInput = -1;
  const int kMaximalStringLength = 7;

  std::string user_string_;
};

#endif  // USER_INPUT_HANDLER_H
