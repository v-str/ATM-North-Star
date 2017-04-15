﻿#include "credit_calculator.h"

#include <cmath>

int CreditCalculator::CalculateMaxCreditSum(int cash) {
  return max_credit_sum_ = multiplier_ * cash;
}

void CreditCalculator::SetCreditSum(int credit_sum) {
  credit_sum_ = credit_sum;
}

void CreditCalculator::SetCreditTerm(int months) { credit_term_ = months; }

void CreditCalculator::CalculateCredit() { payments_.resize(credit_term_); }

double CreditCalculator::AnnuityMonthlyPayment() {
  double persent_interest_rate = (interest_rate_ / 100) / 12;
  double annuity_coefficient_numerator =
      persent_interest_rate *
      std::pow((1 + persent_interest_rate), credit_term_);
  double annuity_coefficient_denumerator =
      std::pow(1 + persent_interest_rate, credit_term_) - 1;
  double annuity_coefficient =
      annuity_coefficient_numerator / annuity_coefficient_denumerator;

  return annuity_coefficient;
}
