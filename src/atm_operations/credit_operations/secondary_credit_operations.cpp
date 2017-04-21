#include "secondary_credit_operations.h"

int SecondaryCreditOperations::GetAmountCreditByMode(int maximal_sum_of_credit,
                                                     int credit_mode) const {
  int sum_of_credit = 0;

  if (credit_mode == kUserCredit) {
    return sum_of_credit = GetCreditSumFromUser(maximal_sum_of_credit);
  } else {
    return sum_of_credit = maximal_sum_of_credit;
  }
}

int SecondaryCreditOperations::GetAmountCreditMonths() const {
  int months = 0;
  do {
    credit_messenger_.ShowInfoAboutCreditTerm();
    months = user_input_.GetValueFromUser();
  } while (!IsMonthCorrect(months));
  return months;
}

double SecondaryCreditOperations::CalculateMonthlyPayment(
    int sum_of_credit, int amount_of_credit_months) const {
  double rate = (sum_of_credit * kRatePerYear) / kFullRate;
  double pay_per_month =
      (sum_of_credit / amount_of_credit_months) + (rate / kOneYear);
  credit_messenger_.ShowCreditTable(pay_per_month, amount_of_credit_months);
  return pay_per_month;
}

bool SecondaryCreditOperations::IsMonthCorrect(int months) const {
  return months > 0 && months < kMaximalCreditTerm;
}

int SecondaryCreditOperations::GetCreditSumFromUser(
    int maximal_sum_of_credit) const {
  int user_credit_sum = 0;

  do {
    credit_messenger_.ShowInfoAboutCreditSum();
    user_credit_sum = user_input_.GetValueFromUser();
  } while (user_credit_sum > maximal_sum_of_credit ||
           user_credit_sum == kInvalidValue || user_credit_sum < 0);

  return user_credit_sum;
}
