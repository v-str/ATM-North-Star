#include "secondary_credit_operations.h"

int SecondaryCreditOperations::GetAmountCreditByMode(
    const int maximal_sum_of_credit, const int credit_mode) const {
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
    credit_messenger_.ShowMonthCreditInfo();
    months = user_input_.GetValueFromUser();
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

int SecondaryCreditOperations::GetCreditSumFromUser(
    int maximal_sum_of_credit) const {
  int user_credit_sum = 0;

  do {
    credit_messenger_.ShowSumCreditInfo();
    user_credit_sum = user_input_.GetValueFromUser();
  } while (user_credit_sum > maximal_sum_of_credit ||
           user_credit_sum == kInvalidValue || user_credit_sum < 0);

  return user_credit_sum;
}
