#include <console_account_menu.h>

#include <account_messenger.h>
#include <application_messenger.h>
#include <main_menu_messenger.h>

#include <console_editor.h>

ConsoleAccountMenu::ConsoleAccountMenu() { FillTitles(); }

void ConsoleAccountMenu::SetAccountInfo(
    const std::vector<std::string>& account_info) {
  account_info_ = account_info;
}

void ConsoleAccountMenu::ShowAccountInfo() {
  ConsoleEditor::ClearScreen();

  for (int i = 0; i < info_title_.size(); ++i) {
    AccountMessenger::DisplayInfoLine(info_title_[i], account_info_[i]);
  }

  ApplicationMessenger::PressEnterToContinue();
}

void ConsoleAccountMenu::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::CashText());
  info_title_.push_back(AccountMessenger::PasswordTooltip());
}
