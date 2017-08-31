#include <console_account_informer.h>

#include <account_messenger.h>

#include <console_editor.h>

ConsoleAccountInformer::ConsoleAccountInformer() { FillTitles(); }

void ConsoleAccountInformer::SetAccountInfo(
    const std::vector<std::string>& account_info) {
  account_info_ = account_info;
}

void ConsoleAccountInformer::ShowAccountInfo() const {
  ConsoleEditor::ClearScreen();

  for (int i = 0; i < info_title_.size(); ++i) {
    AccountMessenger::DisplayInfoLine(info_title_[i], account_info_[i]);
  }
}

void ConsoleAccountInformer::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::CashText());
  info_title_.push_back(AccountMessenger::CreditText());
  info_title_.push_back(AccountMessenger::PaymentText());
  info_title_.push_back(AccountMessenger::InterestRateText());
  info_title_.push_back(AccountMessenger::CreditTermText());
}

void ConsoleAccountInformer::ResetManipulationFlags() {
  user_want_to_quit_ = false;
  user_want_to_main_menu_ = false;
}
