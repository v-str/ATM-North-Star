#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

class UserInput {
 public:
  static int GetValueFromUser();
  static std::string GetDataFromUser();

 private:
  enum DicisionState { kMainMenu, kExitProgram, kError };

  using string = std::string;

  static const int kInvalidChoice = -1;
  static const int kGoToMain = 1;
  static const int kExit = 2;
  static const int kHalfSecond = 500;
  static bool LineNotEmpty(const string& str);
  static int ConvertLineToChoice(const string& line);
  static std::string GetLineFromUser();
};

#endif  // USER_INPUT_H
