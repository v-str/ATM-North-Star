#ifndef CREDIT_DATA_H
#define CREDIT_DATA_H

class CreditData {
 public:
  CreditData();
  CreditData(const CreditData& credit_data);

  CreditData& operator=(const CreditData& credit_data);

  void SetCreditSum(double credit_sum);
  void SetCreditTerm(int credit_term);
  void SetInterestRate(double interest_rate);
  void SetMonthlyPayment(double monthly_payment);

  double CreditSum() const;
  int CreditTerm() const;
  double InterestRate() const;
  double MonthlyPayment() const;

 private:
  double credit_sum_;
  int credit_term_;
  double interest_rate_;
  double monthly_payment_;
};

#endif  // CREDIT_DATA_H
