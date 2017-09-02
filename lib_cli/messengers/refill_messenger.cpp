#include <refill_messenger.h>

#include <console_editor.h>

void RefillMessenger::ShowNotifyAboutCash() const {
  ConsoleEditor::WriteText("\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditor::WriteText("\n\t# Please enter the sum of money($): ");
}

void RefillMessenger::ShowUserBalance(int balance) const {
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n");
  ConsoleEditor::WriteText("Balance: $" + std::to_string(balance) + ".\n");
  ConsoleEditor::WriteText("\n\t");
  ConsoleEditor::Sleep(kSecond);
}
