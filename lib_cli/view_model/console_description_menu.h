#ifndef CONSOLE_DESCRIPTION_MENU_H
#define CONSOLE_DESCRIPTION_MENU_H

#include <description_messenger.h>

#include <user_input_handler.h>

class ConsoleDescriptionMenu {
 public:
  void RunDescriptionMenu();
  void DisplayDemoSubMenu();

  bool UserWantToInitialMenu() const;
  bool IsUserWantToExitProgram() const;

 private:
  enum ReturnMenu { kInitialMenu = 1, kDemoMenu, kExitProgram };

  enum DemoSubMenu {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kExitInitialMenu,
    kExit
  };

  void DisplaySubmenu(DescriptionMessenger::MessageType message_type);

  void DisplayReturnMenu();

  void DiplayDemoMenuTitleOn();
  void DiplayDemoMenuTitleOff();

  void ResetManipulationFlags();

  bool user_want_to_initial_menu_ = false;
  bool user_want_to_exit_ = false;

  UserInputHandler user_input_handler_;
};

#endif  // CONSOLE_DESCRIPTION_MENU_H
