#ifndef INITIAL_INPUT_H
#define INITIAL_INPUT_H

#include <string>

class InitialInput {
 public:
  static int GetValueFromUser();

 private:
  static std::string GetStringFromUser();
  static bool IsContainExitCharacter(const std::string& user_string);
  static bool IsContainOnlyDigits(const std::string& user_string);
  static int GetDigitsFromString(const std::string& user_string);

  static constexpr int kConsoleMode = 1;
  static constexpr int kGuiMode = 2;
  static constexpr int kExit = 0;
  static constexpr int kInvalidChoice = -1;
};

#endif  // INITIAL_INPUT_H
