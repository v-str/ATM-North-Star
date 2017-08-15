#ifndef CONSOLE_INITIAL_MENU
#define CONSOLE_INITIAL_MENU

#include <menu_input_handler.h>

class ConsoleInitialMenu {
 public:
  enum SubMenu { kExit, kLoginMenu, kRegistrationMenu, kDemoMenu };

  void RunInitialMenu();

  void DisplayFarewellMessage();

  int GetSubMenu() const;

 private:
  void SuggestInputSubMenu();

  void DisplaySplashScreen() const;
  void DisplayInitialMenu() const;

  bool IsInputContainSubMenu();

  MenuInputHandler input_handler_;

  int sub_menu_input_ = 0;
};

#endif  // CONSOLE_INITIAL_MENU
