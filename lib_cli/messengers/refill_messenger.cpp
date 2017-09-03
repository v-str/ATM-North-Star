#include <refill_messenger.h>

#include <console_editor.h>

void RefillMessenger::ShowRefillNotification() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t Notification:\n\t The sum must be > $10 and < $50000\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# If you want to leave this menu, enter:");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 1. Main menu");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# 2. Quit\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\n\t# Please, start enter the desired\n\t# "
      "refill sum, $\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\n\t# Enter: ");
}

void RefillMessenger::ShowUserBalance(int balance) {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kStripLength);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n");
  ConsoleEditor::WriteText("Balance: $" + std::to_string(balance) + ".\n");
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::Sleep(kSecond);
}
