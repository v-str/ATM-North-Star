#include <refill_messenger.h>

#include <console_editor.h>

void RefillMessenger::ShowRefillNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "Notification:\nThe sum of refill must be:\n"
      "- more than $10\n"
      "- less than $50000\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\nIf you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n2. Quit\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\nEnter the refill sum, $: ");
}

void RefillMessenger::ShowSuccessfulCashRefilling() {
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# Balance refill completed successfully.\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
}

void RefillMessenger::ShowIncorrectRefillingMessage() {
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n  Attention\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n# Sum of cash is mismatching the atm-system"
      "\n# requirements."
      "\n# Quit to main menu...\n");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
}

void RefillMessenger::ShowMainMenuQuit() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n# Quit to main menu...");
  ConsoleEditor::Sleep(kSecond);
}
