#ifndef CONSOLE_DESCRIPTION_MENU_H
#define CONSOLE_DESCRIPTION_MENU_H

#include <demo_user_messenger.h>
#include <user_input.h>

class ConsoleDescriptionMenu {
 public:
  void RunDescriptionMenu();
  void DisplayDemoSubMenu();

  bool UserWantToInitialMenu() const;
  bool UserWantToExitProgram() const;

 private:
  enum UserChoice { kDemoMenu = 1, kExitProgram };

  enum DemoSubMenu {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitInitialMenu,
    kExit
  };

  void DisplaySubmenu(DemoUserMessenger::MessageType message_type);

  void SuggestToExit();

  void DiplayDemoMenuTitleOn();
  void DiplayDemoMenuTitleOff();

  bool user_want_to_initial_menu_ = false;
  bool user_want_to_exit_ = false;

  UserInput user_input_;
};

#endif  // CONSOLE_DESCRIPTION_MENU_H
