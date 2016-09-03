#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <string>

#include "demo_user_messanger.h"
#include "system_utility.h"

class UserInput {
  using string = std::string;

 public:
  UserInput() {}

  bool SuggestUserToExit() const;
  int GetChoiceFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;
  void ShowExitMessage() const;

 private:
  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;
  string GetLineFromUser() const;

  SystemUtility utility_;
};

#endif  // CORRECT_INPUT_H
