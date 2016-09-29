#include "secondary_credit_operations.h"

static const int kMaximalCreditTerm = 61;

int SecondaryCreditOperations::GetSumOfCreditFromUser(
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
  } while (!IsMonthCorrect(months));
  return months;
}

bool SecondaryCreditOperations::IsMonthCorrect(int months) {
  return months > 0 && months < kMaximalCreditTerm;
}
