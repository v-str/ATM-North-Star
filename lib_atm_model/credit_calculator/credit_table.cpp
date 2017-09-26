#include <credit_table.h>

#include <iostream>

CreditTable::CreditTable()
    : credit_sum_(0),
      monthly_payment_(0.0),
      percentage_coefficient_(0.0),
      credit_term_months_(0),
      percentages_payment_per_month_(0.0),
      payment_per_month_(0.0) {}

void CreditTable::CalculateCreditTable(int credit_sum, double monthly_payment,
                                       double percentage_coefficient,
                                       int credit_term_months) {
  credit_sum_ = credit_sum;
  monthly_payment_ = monthly_payment;
  percentage_coefficient_ = percentage_coefficient;
  credit_term_months_ = credit_term_months;

  ConstructCreditTable();
}

void CreditTable::ConstructCreditTable() {
  percentages_payment_per_month_ =
      credit_sum_ * (percentage_coefficient_ / kMonthsPerYear);
  payment_per_month_ = monthly_payment_ - percentages_payment_per_month_;

  double credit_dept = credit_sum_ - payment_per_month_;

  std::cout << "\nOSNOVNOY DOLG: " << credit_dept << "\n"
            << "PERCENT COEFFICIENT: " << percentage_coefficient_ << "\n"
            << "PERCENTAGE PAYMENT: " << percentages_payment_per_month_ << "\n"
            << "MONTHLY PAYMENT: " << payment_per_month_ << "\n"
            << "TOTAL: " << percentages_payment_per_month_ + payment_per_month_
            << "\n";
}
