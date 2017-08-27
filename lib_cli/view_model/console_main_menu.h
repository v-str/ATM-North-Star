#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>

#include <user_input_handler.h>

class ConsoleMainMenu {
 public:
  void RunMainMenu();

  void DisplayLogOutMessage() const;

  bool UserWantAccountInfo() const;
  bool UserWantRefill() const;
  bool UserWantWithdraw() const;
  bool UserWantCredit() const;
  bool UserWantStatement() const;

  bool UserWantQuit() const;
  bool UserWantLogOut() const;

 private:
  enum MenuItems {
    kAccountInfo = 1,
    kRefill,
    kCreditApplication,
    kWithdrawal,
    kStatement,
    kLogOut,
    kQuit
  };

  void ProcessMenuUserInput();
  void ResetManipulationFlags();

  bool IsUserInputContainMenuItem(int user_input);

  std::unique_ptr<UserInputHandler> user_input_handler_ =
      std::unique_ptr<UserInputHandler>(new UserInputHandler);

  int user_input_ = 0;

  bool user_want_account_info_ = false;
  bool user_want_refill_ = false;
  bool user_want_withdraw_ = false;
  bool user_want_credit_ = false;
  bool user_want_statement_ = false;

  bool user_want_quit_ = false;
  bool user_want_log_out_ = false;

  bool user_input_contain_menu_item_ = false;
};

#endif  // CONSOLE_MAIN_MENU_H
