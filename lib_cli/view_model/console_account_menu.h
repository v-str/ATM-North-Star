#ifndef CONSOLE_ACCOUNT_MENU_H
#define CONSOLE_ACCOUNT_MENU_H

#include <string>
#include <vector>

class ConsoleAccountMenu {
 public:
  ConsoleAccountMenu();

  void SetAccountInfo(const std::vector<std::string>& account_info);
  void ShowAccountInfo();

  bool UserWantMainMenu() const;
  bool UserWantQuit() const;

 private:
  void FillTitles();

  std::vector<std::string> account_info_;
  std::vector<std::string> info_title_;
};

#endif  // CONSOLE_ACCOUNT_MENU_H
