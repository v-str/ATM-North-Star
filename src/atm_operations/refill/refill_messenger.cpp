#include "refill_messenger.h"

static const int kSecond = 1000;
static const int kSleep = 100;
static const int kFrame = 45;

void RefillMessenger::ShowNotifyAboutCash() const {
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  cout << "\n\t";
  utility_.WriteTextWithDelay(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$");
  cout << "\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  cout << "\n";
  cout << "\t# Please enter the sum of money($): ";
}

void RefillMessenger::ShowUserBalance(const int balance) const {
  cout << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  utility_.WriteTextWithDelay("\n\t# Balance refill completed successfully.");
  WriteUserInfo("Balance", std::to_string(balance));
  cout << "\n\t";
  cin.sync();
  utility_.Sleep(kSecond);
}

void RefillMessenger::WriteUserInfo(
    const RefillMessenger::string &info_title,
    const RefillMessenger::string &value) const {
  cout << "\n\t# " << info_title << ": " << value << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  utility_.Sleep(kSleep);
}
