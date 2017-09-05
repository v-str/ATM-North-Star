#include <withdrawal_messenger.h>

#include <console_editor.h>

void WithdrawalMessenger::ShowWithdrawalNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t\tNotification:\n\tThe sum of withdrawal must be:\n"
      "\t- more than $10\n"
      "\t- less than $10000\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# If you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n\t# Enter the desired sum of withdrawal, $:\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
  ConsoleEditor::IgnoreCinLine();
}

void WithdrawalMessenger::ShowPasswordString() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Please enter your password: XXXX\b\b\b\b");
}

void WithdrawalMessenger::ShowIncorrectPasswordMessage() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered password is incorrect.\n");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Please, enter the required sum: ");
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal(int sum_of_cash,
                                                   int sum_of_withdrawal) {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Withdrawal completed successfully\n\t# Sum($): " +
      std::to_string(sum_of_cash) + "\n\t# Balance($): " +
      std::to_string(sum_of_withdrawal) + "\n\n");
}
