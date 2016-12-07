#include "withdrawal_messenger.h"

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# Sum($): " + std::to_string(sum_of_cash) + "\n");
}

void WithdrawalMessenger::ShowPasswordString() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t# Please enter your password: XXXX");

  console_editor_.WriteTextWithDelayPerSymbol("\b\b\b\b", 50);
}

void WithdrawalMessenger::ShowIncorrectPasswordMessage() const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered password is incorrect.\n");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Please, enter the required sum: ");
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                                   int sum_of_withdrawal) {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Withdrawal completed successfully\n\t# Sum($): " +
      std::to_string(sum_of_cash) + "\n\t# Balance($): " +
      std::to_string(sum_of_withdrawal) + "\n\n");
}
