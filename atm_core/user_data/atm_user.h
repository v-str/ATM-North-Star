#ifndef ATM_USER_H
#define ATM_USER_H

#include "cash_data.h"
#include "credit_data.h"
#include "identification_data.h"

class AtmUser {
 public:
  AtmUser();
  ~AtmUser();

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);

  void SetCash(double cash);
  void AddCash(double cash);
  void WithdrawCash(double cash);

  void SetCreditSum(double credit_sum);
  void SetCreditTerm(int credit_term);
  void SetInterestRate(double interest_rate);
  void SetMonthlyPayment(double monthly_payment);

  std::string Login() const;
  std::string Password() const;
  double Cash() const;
  double CreditSum() const;
  int CreditTerm() const;
  double InterestRate() const;
  double MonthlyPayment() const;

 private:
  IdentificationData* identification_data_ = nullptr;
  CashData* cash_data_ = nullptr;
  CreditData* credit_data_ = nullptr;
};

#endif  // ATM_USER_H
