#include <console_editor_duplicate.h>
#include <notice_messenger.h>

void NoticeMessenger::ShowAcceptableMessageFrame() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText("\n\n\t\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kAccessFrame);
  ConsoleEditorDuplicate::WriteText("\n");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol("\t\t| Access allowed |");
  ConsoleEditorDuplicate::WriteText("\t\t\n\t\t");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kAccessFrame);
  ConsoleEditorDuplicate::WriteText("\t\t\n");
  ConsoleEditorDuplicate::Sleep(kSecond);
}

void NoticeMessenger::ShowIncorrectLoginFrame() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText("\t|");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditorDuplicate::WriteText("|\n");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|\n\t|");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditorDuplicate::WriteText("|\n\n");
}

void NoticeMessenger::ShowIncorrectFormatPassword() const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteText("\n\n\n\n\t|");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditorDuplicate::WriteText("|\n");
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  ConsoleEditorDuplicate::WriteText("\n\t|");
  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditorDuplicate::WriteText("|\n\n\t\t\t");
}

void NoticeMessenger::ShowIncorrectSum() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\tIncorrect sum, Reconnect to repeat.\n\n");
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int amount_of_cash) const {
  ConsoleEditorDuplicate::ClearScreen();
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered sum is incorrect.\n\n");
  ConsoleEditorDuplicate::WriteText("\t# Balance: " +
                                    std::to_string(amount_of_cash) + "\n\n\t");

  ConsoleEditorDuplicate::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditorDuplicate::Sleep(kSleep);
}

void NoticeMessenger::ShowError() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\nData is not correct.\n\n");
}

void NoticeMessenger::ShowSumCreditInfo() const {
  ConsoleEditorDuplicate::WriteTextWithDelayPerSymbol(
      "\nThe entered sum should not\n"
      "exceed the allowed credit.\n\n"
      "Enter the desired sum of credit: $");
}
