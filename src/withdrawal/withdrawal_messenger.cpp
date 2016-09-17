#include "withdrawal_messenger.h"

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  cout << "\t#Sum($): " << sum_of_cash << "\n";
}

void WithdrawalMessenger::ShowPasswordString() const {
  cout << "\t# Please enter your password: XXXX\b\b\b\b";
}
