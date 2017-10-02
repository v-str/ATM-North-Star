#include <console_account_menu.h>

#include <account_messenger.h>
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

  ProcessUserInput();
}

bool ConsoleAccountMenu::UserWantMainMenu() const {
  return user_want_main_menu_;
}

bool ConsoleAccountMenu::UserWantQuit() const { return user_want_quit_; }

void ConsoleAccountMenu::ProcessUserInput() {
  MainMenuMessenger::ShowQuitMenu();

  for (;;) {
    int user_input = user_input_handler_.GetDigitInputFromUser();
    if (IsUserInputCorrect(user_input)) {
      break;
    }

    MainMenuMessenger::ShowIncorrectInput();
  }
}

void ConsoleAccountMenu::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::CashText());
}

void ConsoleAccountMenu::ResetManipulationFlags() {
  user_want_quit_ = false;
  user_want_main_menu_ = false;
}

bool ConsoleAccountMenu::IsUserInputCorrect(int user_input) {
  ResetManipulationFlags();

  if (user_input == kMainMenu) {
    return user_want_main_menu_ = true;
  }
  if (user_input == kQuit) {
    return user_want_quit_ = true;
  }
  return false;
}
