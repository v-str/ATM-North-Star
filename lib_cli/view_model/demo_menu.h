#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <demo_user_messenger.h>
#include <user_input.h>

class DemoMenu {
 public:
  void RunDemoMenu();
  void UserWantToExitProgram();
  void DisplayDemoPointrBasedOnUserChoice();

  bool UserWantToRegistrate() const;
  bool UserWantToLogin() const;

 private:
  enum UserChoice { kMainMenu = 1, kExitProgram };

  enum DemoSubMenu {
    kAccount = 1,
    kRefill,
    kCredit,
    kWidthdrawal,
    kStatement,
    kLogin,
    kRegistration,
    kExit
  };

  void DisplaySubmenu(DemoUserMessenger::MessageType message_type);

  void LeadToRegistration();
  void LeadToLogin();
  void SuggestToExit();

  void DiplayDemoMenuWithTitle();

  bool user_want_to_exit_ = true;
  bool user_want_to_registrate_ = false;
  bool user_want_to_login_ = false;

  UserInput user_input_;
};

#endif  // DEMO_MENU_H
