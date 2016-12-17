#ifndef USER_INPUT_H
#define USER_INPUT_H

#include "notice_messenger.h"
#include "user_messenger.h"

#include <string>

class UserInput {
 public:
  bool SuggestUserToExit() const;
  bool ShowIncorrectMessage() const;
  bool GetResultFromUserAboutExit() const;
  bool SuggestUserToExitWithConfirmationMenu() const;

  static int GetValueFromUser();
  static std::string GetDataFromUser();

 private:
  using string = std::string;

  static const int kInvalidChoice = -1;
  static const int kGoToMain = 1;
  static const int kExit = 2;
  static const int kHalfSecond = 500;
  static bool LineNotEmpty(const string &str);
  static int ConvertLineToChoice(const string &line);
  static std::string GetLineFromUser();

  UserMessenger user_messenger_;
  NoticeMessenger notice_messenger_;
};

#endif  // USER_INPUT_H
