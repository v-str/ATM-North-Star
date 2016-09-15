#include "notice_about_successful_action.h"

void NoticeAboutSuccessfulAction::NoticeAboutSuccessfulRegistration(
    UserIdentifier &user_identifier_) const {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t------------------\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  cout << "\t\t------------------\n";
  utility_.Sleep(1000);
  user_identifier_.InitCredit(0);
  user_identifier_.InitMonthlyPayment(0.0);
  user_identifier_.InitAmountOfCreditMonth(0);
}
