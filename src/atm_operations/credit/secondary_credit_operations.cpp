#include "secondary_credit_operations.h"

static const int kMinimalCreditTerm = 1;
static const int kMaximalCreditTerm = 60;

bool SecondaryCreditOperations::EnrollACredit() const {
  credit_messenger_.ShowEnrollACredit();
  return user_input_.SuggestUserToExit();
}

bool SecondaryCreditOperations::RepealACredit() const {
  credit_messenger_.ShowRepealACreadit();
  return user_input_.SuggestUserToExit();
}

int SecondaryCreditOperations::GetIndividualSumOfCreditFromUser(
    int maximal_sum_of_credit) {
  int user_sum_of_credit = 0;
  do {
    error_.NoticeAboutIncorrectMonths();
    cin >> user_sum_of_credit;
    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);
  return user_sum_of_credit;
}

int SecondaryCreditOperations::GetMonth() {
  int months = 0;
  do {
    credit_messenger_.ShowAmountOfMonthToPayACredit();
    months = user_input_.GetChoiceFromUser();
  } while (IsMonthNotCorrect(months));
  return months;
}  // TODO Выделить условие while в отдельный метод.

bool SecondaryCreditOperations::IsMonthNotCorrect(int months) {
  return (months < kMinimalCreditTerm || months > kMaximalCreditTerm);
}
