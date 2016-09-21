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
