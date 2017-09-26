#include <credit_table.h>

CreditTable::CreditTable()
    : credit_sum_(0),
      monthly_payment_(0.0),
      percentage_coefficient_(0.0),
      credit_term_months_(0) {}

void CreditTable::CalculateCreditTable(int credit_sum, double monthly_payment,
                                       double percentage_coefficient,
                                       int credit_term_months) {
  credit_sum_ = credit_sum;
  monthly_payment_ = monthly_payment;
  percentage_coefficient_ = percentage_coefficient;
  credit_term_months_ = credit_term_months;

  ConstructCreditTable();
}

void CreditTable::ConstructCreditTable() {}
