#ifndef CASH_OPERATOR_H
#define CASH_OPERATOR_H

class CashOperator {
 public:
  void SetCash(int cash);
  void SetCredit(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetAmountOfCreditMonth(int amount_credit_month);

  int GetCash() const;
  int GetCredit() const;
  double GetMonthlyPayment() const;
  int GetAmountOfCreditMonth() const;

  int GetAssignACredit(int sum_of_credit);
  bool IsCreditAvailable();
  int WithdrawCashFromUser(int amount);

  void AddCash(int sum_of_cash);
  void AssignAMonthlyPayment(double pay_per_month);

 private:
  static const int kmininmal_sum_for_credit = 1000;

  int cash_ = 0;
  int credit_ = 0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;
};

#endif  // CASH_OPERATOR_H
