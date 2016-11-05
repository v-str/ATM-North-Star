#include "withdrawal_messenger.h"

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  std::cout << "\t#Sum($): " << sum_of_cash << "\n";
}

void WithdrawalMessenger::ShowPasswordString() const {
  std::cout << "\t# Please enter your password: XXXX\b\b\b\b";
}

void WithdrawalMessenger::ShowIncorrectPasswordMessage() const {
  utility_.ClearScreen();
  utility_.IgnoreCinLine();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered password is incorrect.\n");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() const {
  std::cout << "\n\t# Please, enter the required sum: ";
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                                   int sum_of_withdrawal) {
  utility_.WriteTextWithDelay("\n\t# Withdrawal completed successfully\n");
  std::cout << "\t# Sum($): " << sum_of_cash << "\n";
  std::cout << "\t# Balance($): " << sum_of_withdrawal << "\n\n";
}
