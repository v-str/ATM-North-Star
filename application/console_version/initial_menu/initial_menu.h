#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <quit_menu_handler.h>

class InitialMenu {
 public:
  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunInitialMenu();

  int UserChoice() const;

 private:
  void ShowInitialScreen();
  void RunMenuEventLoop();

  QuitMenuHandler quit_handler_;

  int user_choice_ = 0;
};

#endif  // INITIAL_MENU_H
