#ifndef CONSOLE_INITIAL_MENU
#define CONSOLE_INITIAL_MENU

#include <menu_input_handler.h>

class ConsoleInitialMenu {
 public:
  enum SubMenu { kExit, kLoginMenu, kRegistrationMenu, kDescriptionMenu };

  void RunInitialMenu();
  void DisplayFarewellMessage();

  void DisplayInitialMenu() const;
  void RunSplashScreen() const;
  SubMenu GetSubMenu();

 private:
  void SuggestInputSubMenu();

  bool IsInputContainSubMenu();

  MenuInputHandler menu_input_handler_;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_INITIAL_MENU
