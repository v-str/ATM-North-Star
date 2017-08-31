#ifndef CONSOLE_ACCOUNT_INFORMER_H
#define CONSOLE_ACCOUNT_INFORMER_H

#include <string>
#include <vector>

#include <submenu_input_handler.h>

class ConsoleAccountInformer {
 public:
  ConsoleAccountInformer();

  void SetAccountInfo(const std::vector<std::string>& account_info);
  void ShowAccountInfo();

  bool UserWantMainMenu() const;
  bool UserWantQuit() const;

 private:
  enum SubMenuItem { kMainMenu = 1, kQuit };

  void ProcessUserInput();

  void FillTitles();

  void ResetManipulationFlags();

  std::vector<std::string> account_info_;
  std::vector<std::string> info_title_;

  SubMenuInputHandler submenu_input_handler_;

  bool user_want_to_quit_ = false;
  bool user_want_to_main_menu_ = false;
};

#endif  // CONSOLE_ACCOUNT_INFORMER_H
