#include <refill_messenger.h>

#include <console_editor_duplicate.h>

void RefillMessenger::ShowNotifyAboutCash() const {
  ConsoleEditorDuplicate::WriteText("\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditorDuplicate::WriteText("\n\t");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t Notify:\n\t The sum must be more than\n"
      "\t 10$ and less than 50000$\n\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditorDuplicate::WriteText("\n\t# Please enter the sum of money($): ");
}

void RefillMessenger::ShowUserBalance(int balance) const {
  ConsoleEditorDuplicate::WriteText("\n\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Balance refill completed successfully.\n");
  WriteUserInfo("Balance: $", std::to_string(balance));
  ConsoleEditorDuplicate::WriteText("\n\t");
  ConsoleEditorDuplicate::Sleep(kSecond);
}

void RefillMessenger::WriteUserInfo(const std::string& info_title,
                                    const std::string& value) const {
  ConsoleEditorDuplicate::WriteText("\t# " + info_title + ": " + value +
                                    "\n\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditorDuplicate::Sleep(kSleep);
}
