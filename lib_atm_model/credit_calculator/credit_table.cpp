#include <credit_table.h>

#include <iostream>

CreditTable::CreditTable()
    : credit_sum_(0.0),
      monthly_payment_(0.0),
      percentage_coefficient_(0.0),
      credit_term_months_(0),
      interest_charge_(0.0),
      main_debp_payment_(0.0) {}

void CreditTable::CalculateCreditTable(int credit_sum,
                                       double monthly_payment,
                                       double percentage_coefficient,
                                       int credit_term_months) {
  credit_sum_ = credit_sum;
  monthly_payment_ = monthly_payment;
  percentage_coefficient_ = percentage_coefficient;
  credit_term_months_ = credit_term_months;

  ConstructCreditTable();
}

void CreditTable::ConstructCreditTable() {
  while (credit_sum_ >= monthly_payment_) {
    interest_charge_ = credit_sum_ * (percentage_coefficient_ / kMonthsPerYear);
    main_debp_payment_ = monthly_payment_ - interest_charge_;
    credit_sum_ -= main_debp_payment_;

    interest_charges_.push_back(interest_charge_);
    balance_owed_.push_back(credit_sum_);
    main_debt_payments_.push_back(main_debp_payment_);
  }
  double rest_of_interest_charge = monthly_payment_ - credit_sum_;

  main_debp_payment_ = monthly_payment_ - rest_of_interest_charge;
  credit_sum_ -= main_debp_payment_;

  interest_charges_.push_back(rest_of_interest_charge);
  balance_owed_.push_back(credit_sum_);
  main_debt_payments_.push_back(main_debp_payment_);
}
