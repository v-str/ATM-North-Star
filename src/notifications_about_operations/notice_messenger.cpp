#include "notice_messenger.h"

void NoticeMessenger::ShowAcceptableMessageInFrame() const {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t";
  utility_.WriteSymbolsNTimes('-', 18);
  cout << "\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  cout << "\t\t";
  utility_.WriteSymbolsNTimes('-', 18);
  cout << "\t\t\n";
  utility_.Sleep(1000);
}

void NoticeMessenger::ShowIncorrectLoginFrame() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|";
  utility_.WriteSymbolsNTimes('-', 27);
  cout << "|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  cout << "\t|";
  utility_.WriteSymbolsNTimes('-', 27);
  cout << "|\n\n";
}

void NoticeMessenger::ShowIncorrectFormatPassword() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|";
  utility_.WriteSymbolsNTimes('-', 27);
  cout << "|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  cout << "\t|";
  utility_.WriteSymbolsNTimes('-', 27);
  cout << "|\n\n\t\t\t";
}

void NoticeMessenger::ShowIncorrectData() const {
  utility_.WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit");
  cout << "\t# Enter: ";
  cin.clear();
}

void NoticeMessenger::ShowIncorrectSum() const {
  utility_.WriteTextWithDelay(
      "\n\tIncorrect sum, Reconnect to repeat.\n"
      "\t\t- Press any key - \n\n");
  cin.clear();
}

void NoticeMessenger::ShowUnacceptableWithdrawal(int incorrect_sum,
                                                 int amount_of_cash) const {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered sum is incorrect.\n\n");
  cout << "\t# Entered sum: " << incorrect_sum << "\n\n";
  refill_messenger_.WriteUserInfo("Balance", std::to_string(amount_of_cash));
  utility_.IgnoreCinLine();
}

void NoticeMessenger::ShowError() const {
  utility_.WriteTextWithDelay(
      "\t Data is not correct, please reload the program.\n\n");
  cin.get();
}

void NoticeMessenger::ShowIncorrectfMonths() const {
  utility_.WriteTextWithDelay(
      "The entered amount should not "
      "exceed the allowed credit.\n"
      "Enter the appropriate amount of credit: ");
  cout << "Enter: ";
}
