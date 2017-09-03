#include <refill_messenger.h>

#include <console_editor.h>

void RefillMessenger::ShowRefillNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t\tNotification:\n\t     The sum must be > $10 and < $50000\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# If you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n\t# Please, enter the desired refill sum, $:\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void RefillMessenger::ShowCorrectCashRefilling() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::Sleep(kSecond);
}

void RefillMessenger::ShowIncorrectRefillingNotification() {
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
