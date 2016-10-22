#ifndef CORRECT_INPUT_H
#define CORRECT_INPUT_H

#include <iostream>
#include <string>

#include "notifier.h"
#include "system_utility.h"
#include "user_messenger.h"

using std::cin;
using std::cout;

class UserInput {
  using string = std::string;

 public:
  bool SuggestUserToExit() const;
  int GetChoiceFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;

  bool SuggestUserToExitWithConfirmationMenu();

 private:
  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;
  std::string GetLineFromUser() const;

  SystemUtility utility_;
  Notifier error_message;
  UserMessenger user_messenger_;
};

#endif  // CORRECT_INPUT_H
