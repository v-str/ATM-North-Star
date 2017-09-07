#include <refill_messenger.h>

#include <console_editor.h>

void RefillMessenger::ShowRefillNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t\tNotification:\n\tThe sum of refill must be:\n"
      "\t- more than $10\n"
      "\t- less than $50000\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# If you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n\t# Enter the refill sum, $:\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void RefillMessenger::ShowSuccessfulCashRefilling() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::Sleep(kSecond);
}

void RefillMessenger::ShowIncorrectRefillingMessage() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t\t\t  Attention\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Sum of cash is mismatching the atm-system"
      "\n\t# requirements."
      "\n\t# Quit to main menu...\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# press enter to continue...");
  ConsoleEditor::IgnoreCinLine();
}

void RefillMessenger::ShowIncorrectInputMessage() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Incorrect input, please try again...\n"
      "\t# Enter: ");
}
