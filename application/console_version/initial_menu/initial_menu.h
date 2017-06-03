#ifndef INITIAL_MENU_H
#define INITIAL_MENU_H

#include <demo_mode.h>
#include <menu_input_handler.h>
#include <registrator.h>

namespace cli {

class InitialMenu {
 public:
  enum MenuPoints { kQuit, kDemo, kRegistration, kLogin };

  void RunInitialMenu();

  int UserChoice() const;

 private:
  void ShowInitialScreen();
  void RunInitialMenuEventLoop();
  void RunDemoMode();
  void RunRegistration();

  MenuInputHandler quit_handler_;
  DemoMode demo_mode_;
  Registrator registrator_;

  int user_choice_ = 0;
};
}

#endif  // INITIAL_MENU_H
