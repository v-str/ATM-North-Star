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
  std::cout
      << "\n\t#  |  Credit dept | Percent payment | Monthly payment | Total\n";

  double credit_dept = 0.0;
  int count = 0;

  while (credit_sum_ >= monthly_payment_) {
    percentages_payment_per_month_ =
        credit_sum_ * (percentage_coefficient_ / kMonthsPerYear);
    payment_per_month_ = monthly_payment_ - percentages_payment_per_month_;
    credit_dept = credit_sum_ - payment_per_month_;
    credit_sum_ = credit_dept;
    count++;

    std::cout << "\t" << count << "   " << credit_dept << "        "
              << percentages_payment_per_month_ << "          "
              << payment_per_month_ << "        "
              << percentages_payment_per_month_ + payment_per_month_ << "\n";
  }
}
