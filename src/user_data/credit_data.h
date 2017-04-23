#ifndef CREDIT_DATA_H
#define CREDIT_DATA_H

#include <utility>
#include <vector>

class CreditData {
 public:
  void SetCreditSum(int credit_sum) { credit_sum_ = credit_sum; }
  void SetCreditTerm(int credit_term) { credit_term_ = credit_term; }
  void SetCreditMultiplier(int credit_multiplier) {
    credit_multiplier_ = credit_multiplier;
  }
  void SetCreditOverPayment(double credit_overpayment) {
    credit_overpayment_ = credit_overpayment;
  }
  void SetInterestRate(double interest_rate) { interest_rate_ = interest_rate; }
  void SetPaysheet(const std::vector<std::pair<double, double>>& paysheet) {
    paysheet_ = paysheet;
  }
  void SetMonthlyPayment() { monthly_payment_ = paysheet_[0].first; }
  void SetMonthlyPayment(double monthly_payment) {
    monthly_payment_ = monthly_payment;
  }

  int CreditMultiplier() const { return credit_multiplier_; }
  int CreditSum() const { return credit_sum_; }
  int CreditTerm() const { return credit_term_; }
  double CreditOverpayment() const { return credit_overpayment_; }
  double InterestRate() const { return interest_rate_; }
  double MonthlyPayment() const { return monthly_payment_; }
  const std::vector<std::pair<double, double>>& Paysheet() const {
    return paysheet_;
  }

  bool IsCreditExist() const { return credit_sum_ > 0; }

  CreditData& operator=(const CreditData& credit_data) {
    credit_multiplier_ = credit_data.CreditMultiplier();
    credit_sum_ = credit_data.CreditSum();
    credit_term_ = credit_data.CreditTerm();
    credit_overpayment_ = credit_data.CreditOverpayment();
    interest_rate_ = credit_data.InterestRate();
    monthly_payment_ = credit_data.MonthlyPayment();

    paysheet_ = credit_data.Paysheet();

    return *this;
  }

 private:
  int credit_multiplier_ = 15;
  int credit_sum_ = 0;
  int credit_term_ = 0;
  double credit_overpayment_ = 0.0;
  double interest_rate_ = 14.0;
  double monthly_payment_ = 0.0;

  std::vector<std::pair<double, double>> paysheet_;
};

#endif  // CREDIT_DATA_H
