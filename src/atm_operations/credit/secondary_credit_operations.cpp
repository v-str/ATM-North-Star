#include "secondary_credit_operations.h"

static const int kIndividualCredit = 1;

static const int kMaximalCreditTerm = 61;

credit SecondaryCreditOperations::GetCreditMode(
    const credit maximal_sum_of_credit, const credit credit_mode) {
  credit sum_of_credit = 0;

  if (credit_mode == kIndividualCredit) {
    sum_of_credit = GetSumOfCreditFromUser(maximal_sum_of_credit);
  } else {
    sum_of_credit = maximal_sum_of_credit;
  }

  return sum_of_credit;
}

credit SecondaryCreditOperations::GetSumOfCreditFromUser(
    const credit maximal_sum_of_credit) {
  credit user_sum_of_credit = 0;
  do {
    error_.NoticeAboutIncorrectMonths();
    cin >> user_sum_of_credit;
    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);
  return user_sum_of_credit;
}

credit SecondaryCreditOperations::GetCreditMonth() {
  credit months = 0;
  do {
    credit_messenger_.ShowAmountOfMonthToPayACredit();
    months = user_input_.GetChoiceFromUser();
  } while (!IsMonthCorrect(months));
  return months;
}

bool SecondaryCreditOperations::IsMonthCorrect(credit months) {
  return months > 0 && months < kMaximalCreditTerm;
}
