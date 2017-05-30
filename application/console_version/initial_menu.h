#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <quit_menu_handler.h>

class InitialMenu {
 public:
  void RunInitialMenu();

  int UserChoice() const;

 private:
  void ShowInitialScreen();

  QuitMenuHandler quit_handler_;

  int user_choice_ = -1;
};

#endif  // INITIAL_MENU_H
