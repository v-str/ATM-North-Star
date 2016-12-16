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
  int WithdrawCashFromUser(int amount);

  bool IsCreditAvailable();

  void AddCash(int sum_of_cash);
  void AssignAMonthlyPayment(double pay_per_month);

 private:
  static const int kmininmal_sum_for_credit = 1000;

  int cash_;
  int credit_ ;
  double monthly_payment_;
  int amount_of_credit_month_ ;
};

#endif  // CASH_OPERATOR_H
