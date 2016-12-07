#include "refill_messenger.h"

#include <iostream>

void RefillMessenger::ShowNotifyAboutCash() const {
  // std::cout << "\t";
  console_editor_.WriteText("\t");
  console_editor_.WriteSymbolsNTimes('-', kFrame);
  //  std::cout << "\n\t";
  console_editor_.WriteText("\n\t");
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$\n\t");
  console_editor_.WriteSymbolsNTimes('-', kFrame);
  //  std::cout << "\n";
  //  std::cout << "\t# Please enter the sum of money($): ";
  console_editor_.WriteText("\n\t# Please enter the sum of money($): ");
}

void RefillMessenger::ShowUserBalance(const int balance) const {
  std::cout << "\n\t";
  console_editor_.WriteSymbolsNTimes('-', kFrame);
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  std::cout << "\n\t";
  console_editor_.Sleep(kSecond);
}

void RefillMessenger::WriteUserInfo(
    const RefillMessenger::string &info_title,
    const RefillMessenger::string &value) const {
  std::cout << "\n\t# " << info_title << ": " << value << "\n\t";
  console_editor_.WriteSymbolsNTimes('-', kFrame);
  console_editor_.Sleep(kSleep);
}
