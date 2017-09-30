#include <credit_payments_generator.h>

#include <iostream>

CreditPaymentsGenerator::CreditPaymentsGenerator()
    : credit_sum_(0.0),
      monthly_payment_(0.0),
      percentage_coefficient_(0.0),
      interest_charge_(0.0),
      main_debp_payment_(0.0) {}

void CreditPaymentsGenerator::GenerateCreditPayments(
    int credit_sum, double monthly_payment, double percentage_coefficient) {
  Reset();

  credit_sum_ = credit_sum;
  monthly_payment_ = monthly_payment;
  percentage_coefficient_ = percentage_coefficient;

  FillCreditPaymentArrays();
}

std::vector<double> CreditPaymentsGenerator::SumOfOwedCredit() const {
  return sum_of_owed_credit_;
}

std::vector<double> CreditPaymentsGenerator::SumOfInterestCharges() const {
  return sum_of_interest_charges_;
}

std::vector<double> CreditPaymentsGenerator::SumOfMainDebtPayments() const {
  return sum_of_main_debt_payments_;
}

void CreditPaymentsGenerator::FillCreditPaymentArrays() {
  while (credit_sum_ >= monthly_payment_) {
    interest_charge_ = credit_sum_ * (percentage_coefficient_ / kMonthsPerYear);
    main_debp_payment_ = monthly_payment_ - interest_charge_;
    credit_sum_ -= main_debp_payment_;

    sum_of_interest_charges_.push_back(interest_charge_);
    sum_of_owed_credit_.push_back(credit_sum_);
    sum_of_main_debt_payments_.push_back(main_debp_payment_);
  }
  FillLastPayment();
}

void CreditPaymentsGenerator::FillLastPayment() {
  double rest_of_interest_charge = monthly_payment_ - credit_sum_;

  main_debp_payment_ = monthly_payment_ - rest_of_interest_charge;
  credit_sum_ -= main_debp_payment_;

  sum_of_interest_charges_.push_back(rest_of_interest_charge);
  sum_of_owed_credit_.push_back(credit_sum_);
  sum_of_main_debt_payments_.push_back(main_debp_payment_);
}

void CreditPaymentsGenerator::Reset() {
  sum_of_interest_charges_.clear();
  sum_of_owed_credit_.clear();
  sum_of_main_debt_payments_.clear();
}
