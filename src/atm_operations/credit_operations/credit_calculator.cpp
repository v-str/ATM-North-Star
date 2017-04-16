#include "credit_calculator.h"

#include <cmath>

int CreditCalculator::CalculateMaxCreditSum(int cash, int multiplier) {
  return cash * multiplier;
}

void CreditCalculator::SetCreditSum(CreditData* credit_data, int credit_sum) {
  credit_data->SetCreditSum(credit_sum);
}

void CreditCalculator::SetCreditTerm(CreditData* credit_data, int months) {
  credit_data->SetCreditTerm(months);
}

void CreditCalculator::CalculateCredit(CreditData* credit_data) {
  payments_.resize(credit_data->CreditTerm());
}

double CreditCalculator::AnnuityMonthlyPayment(const CreditData& credit_data) {
  double persent_interest_rate_per_year =
      (credit_data.InterestRate() / 100) / 12;

  double annuity_coefficient_numerator =
      persent_interest_rate_per_year *
      std::pow((1 + persent_interest_rate_per_year), credit_data.CreditTerm());

  double annuity_coefficient_denumerator =
      std::pow(1 + persent_interest_rate_per_year, credit_data.CreditTerm()) -
      1;

  double annuity_coefficient =
      annuity_coefficient_numerator / annuity_coefficient_denumerator;

  double annuity_monthly_payment =
      annuity_coefficient * credit_data.CreditSum();

  return annuity_monthly_payment;
}
