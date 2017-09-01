#ifndef CONSOLE_INITIAL_MENU
#define CONSOLE_INITIAL_MENU

#include <user_input_handler.h>

class ConsoleInitialMenu {
 public:
  enum SubMenu { kLoginMenu = 1, kRegistrationMenu, kDescriptionMenu, kQuit };

  void RunInitialMenu();

  void DisplayFarewellMessage() const;
  void RunSplashScreen() const;

  SubMenu GetSubMenu();

 private:
  void SuggestInputSubMenu();

  bool IsInputContainSubMenu();

  UserInputHandler user_input_handler_;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_INITIAL_MENU
