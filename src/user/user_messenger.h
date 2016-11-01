#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

#include <string>

#include "system_utility.h"

class UserMessenger {
  using string = std::string;

 public:
  void ShowMainMenu();

  void ShowNotifyAboutCash();

  void ShowIncorrectDataMessage();

  void WishAGoodDay() const;
  void ShowMainMenu() const;

  void SuggestUserToExit() const;

  void ShowSuggestionAboutExit() const;
  void ShowIncorrectSumInput() const;

  void ShowIncorrectData() const;

  void ShowIncorrectRegisterData() const;

 private:
  static const int kFrame = 45;

  SystemUtility utility_;
};

#endif  // USER_MESSANGER_H
