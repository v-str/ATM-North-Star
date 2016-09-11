#include "notice_about_error.h"

NoticeAboutError::NoticeAboutError() {}

void NoticeAboutError::ShowIncorrectLoginMessage() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n";
}
