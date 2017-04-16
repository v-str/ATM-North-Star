#ifndef CREDIT_DATA_H
#define CREDIT_DATA_H

class CreditData {
 public:
  void SetMultiplier(int multiplier) { multiplier_ = multiplier; }
  void SetCreditSum(int credit_sum) { credit_sum_ = credit_sum; }
  void SetCreditTerm(int credit_term) { credit_term_ = credit_term; }
  void SetCreditOverPayment(double credit_overpayment) {
    credit_overpayment_ = credit_overpayment;
  }
  void SetInterestRate(double interest_rate) { interest_rate_ = interest_rate; }

  int Multiplier() const { return multiplier_; }
  int CreditSum() const { return credit_sum_; }
  int CreditTerm() const { return credit_term_; }
  double CreditOverpayment() const { return credit_overpayment_; }
  double InterestRate() const { return interest_rate_; }

 private:
  int multiplier_ = 15;
  int credit_sum_ = 0;
  int credit_term_ = 0;
  double credit_overpayment_ = 0.0;
  double interest_rate_ = 14.0;
};

#endif  // CREDIT_DATA_H
