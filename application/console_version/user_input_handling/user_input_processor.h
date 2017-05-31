#ifndef USER_INPUT_PROCESSOR
#define USER_INPUT_PROCESSOR

#include <string>

class UserInputProcessor {
 public:
  virtual ~UserInputProcessor();

  virtual int GetDigitInputFromUser();

  std::string GetStringInputFromUser();
  bool IsContainOnlyDigits(const std::string& user_string);
  int GetDigitsFromString(const std::string& user_string);

 private:
  const int kInvalidChoice = -1;
};

#endif  // USER_INPUT_PROCESSOR
