#include "notice_about_successful_action.h"

void NoticeAboutSuccessfulAction::NoticeAboutSuccessfulRegistration(
    UserIdentifier &user_identifier_) const {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t------------------\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  cout << "\t\t------------------\n";
  utility_.Sleep(1000);
  user_identifier_.SetCredit(0);
  user_identifier_.SetMonthlyPayment(0.0);
  user_identifier_.SetAmountOfCreditMonth(0);
}
