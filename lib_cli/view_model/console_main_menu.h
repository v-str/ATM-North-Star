#ifndef CONSOLE_MAIN_MENU_H
#define CONSOLE_MAIN_MENU_H

#include <memory>
#include <vector>

#include <user_input_handler.h>

class ConsoleMainMenu {
 public:
  ConsoleMainMenu();

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
    kCredit,
    kWithdrawal,
    kStatement,
    kLogOut,
    kQuit
  };

  void ProcessMenuUserInput();

  void DefineMenuItem(int user_input);

  void ResetManipulationFlags();

  bool IsUserInputContainMenuItem() const;

  void FillMenuItemsVector();

  std::unique_ptr<UserInputHandler> user_input_handler_ =
      std::unique_ptr<UserInputHandler>(new UserInputHandler);

  std::vector<bool> user_item_choice_;
};

#endif  // CONSOLE_MAIN_MENU_H
