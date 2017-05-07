#include <withdrawal_messenger.h>

#include <console_editor_duplicate.h>

void WithdrawalMessenger::ShowSumOfWithdrawal(int sum_of_cash) const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Sum($): " + std::to_string(sum_of_cash) + "\n");
}

void WithdrawalMessenger::ShowPasswordString() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t# Please enter your password: XXXX\b\b\b\b");
}

void WithdrawalMessenger::ShowIncorrectPasswordMessage() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered password is incorrect.\n");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Please, enter the required sum: ");
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(
    int sum_of_cash, int sum_of_withdrawal) const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Withdrawal completed successfully\n\t# Sum($): " +
      std::to_string(sum_of_cash) + "\n\t# Balance($): " +
      std::to_string(sum_of_withdrawal) + "\n\n");
}
