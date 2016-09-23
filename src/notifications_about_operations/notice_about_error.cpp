#include "notice_about_error.h"

NoticeAboutError::NoticeAboutError() {}

void NoticeAboutError::NoticeAboutIncorrectLogin() const {
  notice_messenger_.ShowIncorrectLoginFrame();
}

void NoticeAboutError::NoticeAboutIncorrectFormatPasswordMessage() const {
  notice_messenger_.ShowIncorrectFormatPassword();
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

void NoticeAboutError::ShowUnacceptableWithdrawal(int amount_of_cash,
                                                  int incorrect_sum) {
  utility_.ClearScreen();
  utility_.WriteTextWithDelay("\n\t# Sorry, entered sum is incorrect.\n\n");
  cout << "\t# Entered sum: " << incorrect_sum << "\n\n";
  refill_messenger_.WriteUserInfo("Balance", std::to_string(amount_of_cash));
  utility_.IgnoreCinLine();
}

bool NoticeAboutError::ShowIncorrectDataMessage() {
  utility_.WriteTextWithDelay(
      "\t Data is not correct, please reload the program.\n\n");
  cin.get();
  return true;
}
