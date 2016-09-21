#include "notice_messenger.h"

void NoticeMessenger::ShowFrame() const {
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
