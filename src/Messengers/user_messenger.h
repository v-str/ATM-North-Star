#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

#include "text_editor.h"

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

  TextEditor text_editor_;
};

#endif  // USER_MESSANGER_H
