#include "withdrawal_messenger.h"

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  cout << "\t#Sum($): " << sum_of_cash << "\n";
}

void WithdrawalMessenger::ShowPasswordString() const {
  cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                                   int sum_of_withdrawal) {
  utility_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  cout << "\t# Sum($): " << sum_of_cash << "\n";
  cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}
