#include <console_account_informer.h>

#include <account_messenger.h>

void ConsoleAccountInformer::SetAccountInfo(
    const std::vector<std::string>& account_info) {
  account_info_ = account_info;
}
