#ifndef DEMO_MENU_H
#define DEMO_MENU_H

#include <demo_user_messenger.h>
#include <user_input.h>

namespace cli {

class DemoMenu {
 public:
  void RunDemoMenu();
  void UserWantToExitProgram();
  void DisplayDemoPointrBasedOnUserChoice();

  bool UserWantToRegistrate() const;
  bool UserWantToLogin() const;

 private:
  enum UserChoice { kMainMenu = 1, kExit };

  enum MenuPoints {
    kAccountPoint = 1,
    kRefillPoint,
    kCreditPoint,
    kWidthdrawalPoint,
    kStatementPoint,
    kLoginPoint,
    kRegistrationPoint,
    kExitPoint
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
}

#endif  // DEMO_MENU_H
