#ifndef USER_INPUT_PROCESSOR
#define USER_INPUT_PROCESSOR

#include <string>

class UserInputProcessor {
 public:
  static int GetUserInput();
  static std::string GetStringFromUser();

 private:
  static bool IsContainQuitCharacter(const std::string& user_string);
  static bool IsContainOnlyDigits(const std::string& user_string);
  static int GetDigitsFromString(const std::string& user_string);

  static constexpr int kQuit = 0;
  static constexpr int kInvalidChoice = -1;
};

#endif  // USER_INPUT_PROCESSOR
