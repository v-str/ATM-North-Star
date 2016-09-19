#include "refill_messenger.h"

void RefillMessenger::ShowNotifyAboutCash() const {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', 45);
  cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', 45);
  cout << "\n";
  cout << "\t# Please enter the sum of money($): ";
}

void RefillMessenger::ShowUserBalance(const int balance) const {
  cout << "\n\t";
  utility_.WriteSymbolsNTimes('-', 45);
  utility_.WriteTextWithDelay("\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  cout << "\n\t";
  cin.sync();
  utility_.Sleep(1000);
}

void RefillMessenger::WriteUserInfo(
    const RefillMessenger::string &info_title,
    const RefillMessenger::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', 45);
  utility_.Sleep(100);
}
