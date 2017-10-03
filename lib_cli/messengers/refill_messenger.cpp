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
      "\n\tIf you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t2. Quit\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\n\tEnter the refill sum, $: ");
}

void RefillMessenger::ShowSuccessfulCashRefilling() {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
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
}

void RefillMessenger::ShowMainMenuQuit() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Quit to main menu...");
  ConsoleEditor::Sleep(kSecond);
}
