#include "notice_messenger.h"

void NoticeMessenger::ShowAcceptableMessageFrame() const {
  console_editor_.ClearScreen();
  console_editor_.WriteText("\n\n\t\t");
  console_editor_.WriteSymbolsNTimes("-", kAccessFrame);
  console_editor_.WriteText("\n");
  console_editor_.WriteTextWithDelayPerSymbol("\t\t| Access allowed |");
  console_editor_.WriteText("\t\t\n\t\t");
  console_editor_.WriteSymbolsNTimes("-", kAccessFrame);
  console_editor_.WriteText("\t\t\n");
  console_editor_.Sleep(kSecond);
}

void NoticeMessenger::ShowIncorrectLoginFrame() const {
  console_editor_.ClearScreen();
  console_editor_.WriteText("\t|");
  console_editor_.WriteSymbolsNTimes("-", kIncorrectDataFrame);
  console_editor_.WriteText("|\n");
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|\n\t|");
  console_editor_.WriteSymbolsNTimes("-", kIncorrectDataFrame);
  console_editor_.WriteText("|\n\n");
}

void NoticeMessenger::ShowIncorrectFormatPassword() const {
  console_editor_.ClearScreen();
  console_editor_.WriteText("\n\n\n\n\t|");
  console_editor_.WriteSymbolsNTimes("-", kIncorrectDataFrame);
  console_editor_.WriteText("|\n");
  console_editor_.WriteTextWithDelayPerSymbol(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  console_editor_.WriteText("\n\t|");
  console_editor_.WriteSymbolsNTimes("-", kIncorrectDataFrame);
  console_editor_.WriteText("|\n\n\t\t\t");
}

void NoticeMessenger::ShowIncorrectSum() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\tIncorrect sum, Reconnect to repeat.\n\n");
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int amount_of_cash) const {
  console_editor_.ClearScreen();
  console_editor_.WriteTextWithDelayPerSymbol(
      "\n\t# Sorry, entered sum is incorrect.\n\n");
  console_editor_.WriteText("\t# Balance: " + std::to_string(amount_of_cash) +
                            "\n\n\t");

  console_editor_.WriteSymbolsNTimes("-", kFrame);
  console_editor_.Sleep(kSleep);
}

void NoticeMessenger::ShowError() const {
  console_editor_.WriteTextWithDelayPerSymbol("\nData is not correct.\n\n");
}

void NoticeMessenger::ShowSumCreditInfo() const {
  console_editor_.WriteTextWithDelayPerSymbol(
      "\nThe entered sum should not "
      "exceed the allowed credit.\n\n"
      "Enter the appropriate sum of credit: $");
}
