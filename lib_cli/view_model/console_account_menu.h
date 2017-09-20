#ifndef CONSOLE_ACCOUNT_MENU_H
#define CONSOLE_ACCOUNT_MENU_H

#include <string>
#include <vector>

#include <user_input_handler.h>

class ConsoleAccountMenu {
 public:
  ConsoleAccountMenu();

  void SetAccountInfo(const std::vector<std::string>& account_info);
  void ShowAccountInfo();

  bool UserWantMainMenu() const;
  bool UserWantQuit() const;

 private:
  enum SubMenuItem { kMainMenu = 1, kQuit };

  void ProcessUserInput();
  void FillTitles();
  void ResetManipulationFlags();

  bool IsUserInputCorrect(int user_input);

  std::vector<std::string> account_info_;
  std::vector<std::string> info_title_;

  UserInputHandler user_input_handler_;

  bool user_want_quit_ = false;
  bool user_want_main_menu_ = false;
};

#endif  // CONSOLE_ACCOUNT_MENU_H
