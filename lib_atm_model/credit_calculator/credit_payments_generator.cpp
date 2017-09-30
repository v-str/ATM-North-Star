#include <credit_payments_generator.h>

#include <iomanip>
#include <sstream>

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

  CalculatePaymentTable();
}

std::vector<std::string> CreditPaymentsGenerator::SumOfOwedCredit() const {
  return sum_of_owed_credit_;
}

std::vector<std::string> CreditPaymentsGenerator::SumOfInterestCharges() const {
  return sum_of_interest_charges_;
}

std::vector<std::string> CreditPaymentsGenerator::SumOfMainDebtPayments()
    const {
  return sum_of_main_debt_payments_;
}

void CreditPaymentsGenerator::CalculatePaymentTable() {
  while (credit_sum_ >= monthly_payment_) {
    interest_charge_ = credit_sum_ * (percentage_coefficient_ / kMonthsPerYear);
    main_debp_payment_ = monthly_payment_ - interest_charge_;
    credit_sum_ -= main_debp_payment_;

    FillPaymentContainers(interest_charge_, credit_sum_, main_debp_payment_);
  }
  CalculateLastPayment();
}

void CreditPaymentsGenerator::CalculateLastPayment() {
  double rest_of_interest_charge = monthly_payment_ - credit_sum_;

  main_debp_payment_ = monthly_payment_ - rest_of_interest_charge;
  credit_sum_ -= main_debp_payment_;

  FillPaymentContainers(rest_of_interest_charge, credit_sum_,
                        main_debp_payment_);
}

void CreditPaymentsGenerator::FillPaymentContainers(
    double sum_of_owed_credit,
    double sum_of_interest_charges,
    double sum_of_main_debt_payments) {
  sum_of_interest_charges_.push_back(ConvertToString(sum_of_owed_credit));
  sum_of_owed_credit_.push_back(ConvertToString(sum_of_interest_charges));
  sum_of_main_debt_payments_.push_back(
      ConvertToString(sum_of_main_debt_payments));
}

std::string CreditPaymentsGenerator::ConvertToString(double value) const {
  std::stringstream conversion_stream;
  conversion_stream << std::fixed << std::setprecision(2) << value;

  return conversion_stream.str();
}

void CreditPaymentsGenerator::Reset() {
  sum_of_interest_charges_.clear();
  sum_of_owed_credit_.clear();
  sum_of_main_debt_payments_.clear();
}
