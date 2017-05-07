#include <notice_messenger.h>

#include <console_editor.h>

void NoticeMessenger::ShowAcceptableMessageFrame() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\n\n\t\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kAccessFrame);
  ConsoleEditor::WriteText("\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol("\t\t| Access allowed |");
  ConsoleEditor::WriteText("\t\t\n\t\t");
  ConsoleEditor::WriteSymbolsNTimes("-", kAccessFrame);
  ConsoleEditor::WriteText("\t\t\n");
  ConsoleEditor::Sleep(kSecond);
}

void NoticeMessenger::ShowIncorrectLoginFrame() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\t|");
  ConsoleEditor::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditor::WriteText("|\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|\n\t|");
  ConsoleEditor::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditor::WriteText("|\n\n");
}

void NoticeMessenger::ShowIncorrectFormatPassword() {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteText("\n\n\n\n\t|");
  ConsoleEditor::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditor::WriteText("|\n");
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  ConsoleEditor::WriteText("\n\t|");
  ConsoleEditor::WriteSymbolsNTimes("-", kIncorrectDataFrame);
  ConsoleEditor::WriteText("|\n\n\t\t\t");
}

void NoticeMessenger::ShowIncorrectSum() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\tIncorrect sum, Reconnect to repeat.\n\n");
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int amount_of_cash) {
  ConsoleEditor::ClearScreen();
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered sum is incorrect.\n\n");
  ConsoleEditor::WriteText("\t# Balance: " + std::to_string(amount_of_cash) +
                           "\n\n\t");

  ConsoleEditor::WriteSymbolsNTimes("-", kFrame);
  ConsoleEditor::Sleep(kSleep);
}

void NoticeMessenger::ShowError() {
  ConsoleEditor::WriteTextWithDelayPerSymbol("\nData is not correct.\n\n");
}

void NoticeMessenger::ShowSumCreditInfo() {
  ConsoleEditor::WriteTextWithDelayPerSymbol(
      "\nThe entered sum should not\n"
      "exceed the allowed credit.\n\n"
      "Enter the desired sum of credit: $");
}
