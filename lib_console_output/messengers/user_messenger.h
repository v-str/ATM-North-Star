#ifndef USER_MESSANGER_H
#define USER_MESSANGER_H

#include "console_editor.h"

class UserMessenger {
  using string = std::string;

public:
  void ShowMainMenu();

  void WishAGoodDay() const;
  void ShowMainMenu() const;

  void AskToExit() const;

  void SuggestToExit() const;
  void ShowIncorrectInput() const;
  void ShowIncorrectMainMenuInput() const;

  void ShowIncorrectRegisterData() const;

private:
  static const int kFrame = 45;

  ConsoleEditor console_editor_;
};

#endif // USER_MESSANGER_H
