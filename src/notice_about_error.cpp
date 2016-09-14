#include "notice_about_error.h"

NoticeAboutError::NoticeAboutError() {}

void NoticeAboutError::NoticeAboutIncorrectLoginMessage() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect login.           |\n"
      "\t|It must be more than 1 and |\n"
      "\t|less than 20 symbols.      |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n";
}

void NoticeAboutError::NoticeAboutIncorrectFormatPasswordMessage() const {
  utility_.ClearScreen();
  cout << "\n\n\n\n\t|---------------------------|\n";
  utility_.WriteTextWithDelay(
      "\t|Incorrect password.        |\n"
      "\t|It must be in XXXX format. |\n"
      "\t|Please, reload the program.|");
  cout << "\t|---------------------------|\n\n\t\t\t";
}

void NoticeAboutError::NoticeAboutIncorrectDataMessage() const {
  utility_.WriteTextWithDelay(
      "\n\t# Data is not correct,\n"
      "\t# return to main?\n"
      "\t# 1. Yes\n"
      "\t# 2. No, exit");
  cout << "\t# Enter: ";
  cin.clear();
}

void NoticeAboutError::NoticeAboutIncorrectSum() const {
  cout << "\n\tIncorrect sum, Reconnect to repeat.\n"
          "\t\t - Press any key - \n\n";
  cin.clear();
}

void NoticeAboutError::ShowUnacceptableWithdrawal(
    const AccountInfo &account_info, int incorrect_sum) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered sum is incorrect.\n\n");
  cout << "\t# Entered sum: " << incorrect_sum << "\n\n";
  user_messenger_.WriteUserInfo("Balance", std::to_string(account_info.cash_));
  utility_.IgnoreCinLine();
}

bool NoticeAboutError::ShowIncorrectDataMessage() {
    utility_.WriteTextWithDelay(
        "\t Data is not correct, please reload the program.\n\n");
    cin.get();
    return true;
}
// a;dfljaslfkjas;fklj
