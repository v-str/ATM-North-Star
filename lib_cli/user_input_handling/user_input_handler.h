#ifndef USER_INPUT_HANDLER_H
#define USER_INPUT_HANDLER_H

#include <string>

class UserInputHandler {
 public:
  int GetDigitInputFromUser();

  std::string GetStringInputFromUser();

 private:
  bool IsContainOnlyDigits(const std::string& user_string);
  int GetDigitsFromString(const std::string& user_string);

  const int kInvalidInput = -1;
  const int kMaximalStringLength = 7;
};

#endif  // USER_INPUT_HANDLER_H
