#include <console_account_informer.h>

#include <account_messenger.h>

ConsoleAccountInformer::ConsoleAccountInformer() { FillTitles(); }

void ConsoleAccountInformer::SetAccountInfo(
    const std::vector<std::string>& account_info) {}

void ConsoleAccountInformer::FillTitles() {
  info_title_.push_back(AccountMessenger::LoginText());
  info_title_.push_back(AccountMessenger::BalanceText());
  info_title_.push_back(AccountMessenger::CreditText());
  info_title_.push_back(AccountMessenger::PaymentText());
  info_title_.push_back(AccountMessenger::TermText());
}
