#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <string>

#include "notice_messenger.h"
#include "user_messenger.h"

class UserInput {
 public:
  bool SuggestUserToExit() const;
  int GetValueFromUser() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;

  bool SuggestUserToExitWithConfirmationMenu();

  std::string GetDataFromUser();

 private:
  using string = std::string;

  static const int kInvalidChoice = -1;
  static const int kGoToMain = 1;
  static const int kExit = 2;
  static const int kHalfSecond = 500;

  int ConvertLineToChoice(const string &line) const;
  bool LineNotEmpty(const string &str) const;

  std::string GetLineFromUser() const;

  UserMessenger user_messenger_;
  NoticeMessenger notice_messenger_;
};

#endif  // USER_INPUT_H
