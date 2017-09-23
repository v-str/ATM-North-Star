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
      "\n\n\t# Enter the sum of withdrawal, $: ");
}

void WithdrawalMessenger::RequirePasswordMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t# Please enter your password: ");
}

void WithdrawalMessenger::EnterSumOfWithdrawal() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Please, enter the required sum: ");
}

void WithdrawalMessenger::ShowSuccessfulWithdrawal() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Withdrawal completed successfully.\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::Sleep(kSecond);
}

void WithdrawalMessenger::IncorrectWithdrawalMessage() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t\t\t  Attention\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Incorrect withdrawal parameters. "
      "\n\t# Be sure that both withdrawal sum and"
      "\n\t# password is correct and try again."
      "\n\t# Quit to main menu...\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# press enter to continue...");
  ConsoleEditor::IgnoreCinLine();
}
