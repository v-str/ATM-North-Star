#ifndef USER_INPUT_HANDLER_H
#define USER_INPUT_HANDLER_H

#include <string>

class UserInputHandler {
 public:
  virtual ~UserInputHandler();

  virtual int GetDigitInputFromUser();

  std::string GetStringInputFromUser();
  bool IsContainOnlyDigits(const std::string& user_string);
  int GetDigitsFromString(const std::string& user_string);

 private:
  const int kInvalidChoice = -1;
  const int kMaximalStringLength = 1;
};

#endif  // USER_INPUT_HANDLER_H
