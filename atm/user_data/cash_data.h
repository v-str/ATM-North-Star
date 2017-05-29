#ifndef CASH_DATA_H
#define CASH_DATA_H

class CashData {
 public:
  CashData();

  void SetCash(double cash);
  void AddCash(double cash);
  void WithdrawCash(double cash);

  double Cash() const;

 private:
  double cash_;
};

#endif  // CASH_DATA_H
