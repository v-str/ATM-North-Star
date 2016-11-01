#include "refill_messenger.h"

void RefillMessenger::ShowNotifyAboutCash() const {
  std::cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  std::cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  std::cout << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  std::cout << "\n";
  std::cout << "\t# Please enter the sum of money($): ";
}

void RefillMessenger::ShowUserBalance(const int balance) const {
  std::cout << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  utility_.WriteTextWithDelay("\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  std::cout << "\n\t";
  std::cin.sync();
  utility_.Sleep(kSecond);
}

void RefillMessenger::WriteUserInfo(
    const RefillMessenger::string &info_title,
    const RefillMessenger::string &value) const {
  std::cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  utility_.Sleep(kSleep);
}
