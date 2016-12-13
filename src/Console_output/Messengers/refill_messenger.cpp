#include "refill_messenger.h"

void RefillMessenger::ShowNotifyAboutCash() const {
  console_editor_.WriteText("\t");
  console_editor_.WriteSymbolsNTimes("-", kFrame);
  console_editor_.WriteText("\n\t");
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$\n\t");
  console_editor_.WriteSymbolsNTimes("-", kFrame);
  console_editor_.WriteText("\n\t# Please enter the sum of money($): ");
}

void RefillMessenger::ShowUserBalance(const int balance) const {
  console_editor_.WriteText("\n\t");
  console_editor_.WriteSymbolsNTimes("-", kFrame);
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n");
  WriteUserInfo("Balance: $", std::to_string(balance));
  console_editor_.WriteText("\n\t");
  console_editor_.Sleep(kSecond);
}

void RefillMessenger::WriteUserInfo(
    const RefillMessenger::string &info_title,
    const RefillMessenger::string &value) const {
  console_editor_.WriteText("\t# " + info_title + ": " + value + "\n\t");
  console_editor_.WriteSymbolsNTimes("-", kFrame);
  console_editor_.Sleep(kSleep);
}
