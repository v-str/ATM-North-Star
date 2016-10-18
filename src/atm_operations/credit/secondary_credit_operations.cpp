#include "secondary_credit_operations.h"

static const int kIndividualCredit = 1;
static const int kRatePerYear = 14;
static const int kFullRate = 100;
static const int kOneYear = 12;
static const int kMaximalCreditTerm = 61;

int SecondaryCreditOperations::GetAmountCreditByMode(
    const int maximal_sum_of_credit, const int credit_mode) {
  int sum_of_credit = 0;

  if (credit_mode == kIndividualCredit) {
    sum_of_credit = GetSumOfCreditFromUser(maximal_sum_of_credit);
  } else {
    sum_of_credit = maximal_sum_of_credit;
  }

  return sum_of_credit;
}

int SecondaryCreditOperations::GetSumOfCreditFromUser(
    const int maximal_sum_of_credit) {
  int user_sum_of_credit = 0;
  do {
    error_.NoticeAboutIncorrectMonths();
    cin >> user_sum_of_credit;
    utility_.IgnoreCinLine();
  } while (user_sum_of_credit > maximal_sum_of_credit);
  return user_sum_of_credit;
}

int SecondaryCreditOperations::GetAmountCreditMonths() {
  int months = 0;
  do {
    credit_messenger_.ShowAmountOfMonthToPayACredit();
    months = user_input_.GetChoiceFromUser();
  } while (!IsMonthCorrect(months));
  return months;
}

double SecondaryCreditOperations::CalculateMonthlyPayment(
    const int sum_of_credit, const int amount_of_credit_months) const {

  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month =
      (sum_of_credit / amount_of_credit_months) + (rate / kOneYear);
  credit_messenger_.ShowTableOfCredit(pay_per_month, amount_of_credit_months);
  return pay_per_month;
}

bool SecondaryCreditOperations::IsMonthCorrect(int months) {
  return months > 0 && months < kMaximalCreditTerm;
}
