#include "notice_messenger.h"

#include <iostream>

void NoticeMessenger::ShowAcceptableMessageFrame() const {
  text_editor_.ClearScreen();
  std::cout << "\n\n\t\t";
  text_editor_.WriteSymbolsNTimes('-', kAccessFrame);
  std::cout << "\n";
  text_editor_.WriteTextWithDelay("\t\t| Access allowed |");
  std::cout << "\t\t\n\t\t";
  text_editor_.WriteSymbolsNTimes('-', kAccessFrame);
  std::cout << "\t\t\n";
  text_editor_.Sleep(kSecond);
}

void NoticeMessenger::ShowIncorrectLoginFrame() const {
  text_editor_.ClearScreen();
  std::cout << "\n\n\n\n\t|";
  text_editor_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n";
  text_editor_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  std::cout << "\n\t|";
  text_editor_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n\n";
}

void NoticeMessenger::ShowIncorrectFormatPassword() const {
  text_editor_.ClearScreen();
  std::cout << "\n\n\n\n\t|";
  text_editor_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n";
  text_editor_.WriteTextWithDelay(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  std::cout << "\n\t|";
  text_editor_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n\n\t\t\t";
}

void NoticeMessenger::ShowIncorrectData() const {
  text_editor_.WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit\n");
  std::cout << "\t# Enter: ";
}

void NoticeMessenger::ShowIncorrectSum() const {
  text_editor_.WriteTextWithDelay("\n\tIncorrect sum, Reconnect to repeat.\n\n");
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int amount_of_cash) const {
  text_editor_.ClearScreen();
  text_editor_.WriteTextWithDelay("\n\t# Sorry, entered sum is incorrect.\n\n");
  std::cout << "\t# Balance: " << amount_of_cash << "\n\n\t";

  text_editor_.WriteSymbolsNTimes('-', kFrame);
  text_editor_.Sleep(kSleep);
}

void NoticeMessenger::ShowError() const {
  text_editor_.WriteTextWithDelay("\tData is not correct.\n\n");
}

void NoticeMessenger::ShowSumCreditInfo() const {
  text_editor_.WriteTextWithDelay(
      "\nThe entered sum should not "
      "exceed the allowed credit.\n\n"
      "Enter the appropriate sum of credit: $");
}
