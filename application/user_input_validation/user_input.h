#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

class UserInput {
  using string = std::string;

 public:
  static int GetValueFromUser();
  static std::string GetDataFromUser();

 private:
  static std::string GetLineFromUser();
  static bool LineNotEmpty(const string& str);
  static int ConvertLineToChoice(const string& line);

  static const int kInvalidChoice = -1;
  static const int kGoToMain = 1;
  static const int kExit = 2;
};

#endif  // USER_INPUT_H
