#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <demo_mode.h>
#include <quit_menu_handler.h>

class InitialMenu {
 public:
  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunInitialMenu();

  int UserChoice() const;

 private:
  void ShowInitialScreen();
  void RunMenuEventLoop();

  void RunDemoMode();

  QuitMenuHandler quit_handler_;
  DemoMode demo_mode_;

  int user_choice_ = 0;
};

#endif  // INITIAL_MENU_H
