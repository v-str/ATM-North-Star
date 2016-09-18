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
