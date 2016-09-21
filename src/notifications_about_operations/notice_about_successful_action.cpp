#include "notice_about_successful_action.h"

void NoticeAboutSuccessfulAction::NoticeAboutSuccessfulRegistration(
    CashOperator &cash_operator) const {
  utility_.IgnoreCinLine();
  utility_.ClearScreen();
  cout << "\n\n\t\t";
  utility_.WriteSymbolsNTimes('-', 18);
  cout << "\n";
  utility_.WriteTextWithDelay("\t\t| Access allowed |");
  cout << "\t\t";
  utility_.WriteSymbolsNTimes('-', 17);
  cout << "\t\t\n";
  utility_.Sleep(1000);
  cash_operator.SetCredit(0);
  cash_operator.SetMonthlyPayment(0.0);
  cash_operator.SetAmountOfCreditMonth(0);
}
