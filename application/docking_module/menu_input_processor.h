#ifndef MENU_INPUT_PROCESSOR
#define MENU_INPUT_PROCESSOR

#include <string>

class MenuInputProcessor {
 public:
  static int GetMenuItem();

 private:
  static std::string GetStringFromUser();
  static bool IsContainExitCharacter(const std::string& user_string);
  static bool IsContainOnlyDigits(const std::string& user_string);
  static int GetDigitsFromString(const std::string& user_string);

  static constexpr int kQuit = 0;
  static constexpr int kInvalidChoice = -1;
};

#endif  // MENU_INPUT_PROCESSOR
