#ifndef CASH_OPERATOR_H
#define CASH_OPERATOR_H

class CashOperator {
 public:
  void SetCash(int cash);
  void AddCash(int cash);

  int Cash() const;

  int WithdrawCash(int cash);

 private:
  int cash_ = 0;
};

#endif  // CASH_OPERATOR_H
