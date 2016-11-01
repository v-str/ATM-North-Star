#ifndef DATA_INPUT_H
#define DATA_INPUT_H

#include <string>

#include "notifier.h"
#include "system_utility.h"
#include "user_messenger.h"

class DataInput {
 public:
  bool SuggestUserToExit() const;
  int GetChoiceFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;

  bool SuggestUserToExitWithConfirmationMenu();

 private:
  using string = std::string;

  static const int kInvalidChoice = -1;
  static const int kGoToMain = 1;
  static const int kExit = 2;
  static const int kSecond = 1000;

  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;
  std::string GetLineFromUser() const;

  SystemUtility utility_;
  Notifier error_message;
  UserMessenger user_messenger_;
};

#endif  // DATA_INPUT_H
