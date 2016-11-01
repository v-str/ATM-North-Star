#include "notice_messenger.h"

#include <iostream>

void NoticeMessenger::ShowAcceptableMessageFrame() const {
  utility_.ClearScreen();
  std::cout << "\n\n\t\t";
  utility_.WriteSymbolsNTimes('-', kAccessFrame);
  std::cout << "\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  std::cout << "\t\t\n\t\t";
  utility_.WriteSymbolsNTimes('-', kAccessFrame);
  std::cout << "\t\t\n";
  utility_.Sleep(kSecond);
}

void NoticeMessenger::ShowIncorrectLoginFrame() const {
  utility_.ClearScreen();
  std::cout << "\n\n\n\n\t|";
  utility_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  std::cout << "\t|";
  utility_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n\n";
}

void NoticeMessenger::ShowIncorrectFormatPassword() const {
  utility_.ClearScreen();
  std::cout << "\n\n\n\n\t|";
  utility_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  std::cout << "\t|";
  utility_.WriteSymbolsNTimes('-', kIncorrectDataFrame);
  std::cout << "|\n\n\t\t\t";
}

void NoticeMessenger::ShowIncorrectData() const {
  utility_.WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit");
  std::cout << "\t# Enter: ";
  std::cin.clear();
}

void NoticeMessenger::ShowIncorrectSum() const {
  utility_.WriteTextWithDelay(
      "\n\tIncorrect sum, Reconnect to repeat.\n"
      "\t\t- Press any key - \n\n");
  std::cin.clear();
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int incorrect_sum,
                                                 int amount_of_cash) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered sum is incorrect.\n\n");
  std::cout << "\t# Entered sum: " << incorrect_sum << "\n\n";

  std::cout << "\n\t# "
       << "Balance"
       << ": " << amount_of_cash << "\n\t";
  utility_.WriteSymbolsNTimes('-', kFrame);
  utility_.Sleep(kSleep);

  utility_.IgnoreCinLine();
}

void NoticeMessenger::ShowError() const {
  utility_.WriteTextWithDelay(
      "\tData is not correct, please reload the program.\n\n");
  std::cin.get();
}

void NoticeMessenger::ShowIncorrectfMonths() const {
  utility_.WriteTextWithDelay(
      "The entered amount should not "
      "exceed the allowed credit.\n"
      "Enter the appropriate amount of credit: ");
  std::cout << "Enter: ";
}
