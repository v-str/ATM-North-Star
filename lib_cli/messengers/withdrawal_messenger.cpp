#include <withdrawal_messenger.h>

#include <console_editor.h>

void WithdrawalMessenger::ShowWithdrawalNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Notification:\nThe sum of withdrawal must be:\n"
      "- more than $10\n"
      "- less than $10000\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# If you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n# 2. Quit\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n# Enter the sum of withdrawal, $: ");
}

void WithdrawalMessenger::RequirePasswordMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("# Please enter your password: ");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# Please, enter the required sum: ");
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal() {
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# Withdrawal completed successfully.\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
}

void WithdrawalMessenger::IncorrectWithdrawalMessage() {
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n  Attention\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# Incorrect withdrawal parameters. "
      "\n# Be sure that both withdrawal sum and"
      "\n# password is correct and try again."
      "\n# Quit to main menu...\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
}
