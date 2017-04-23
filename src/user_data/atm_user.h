#ifndef ATM_USER_H
#define ATM_USER_H

#include <memory>

#include "cash_operator.h"
#include "credit_data.h"
#include "identification_data.h"

class AtmUser {
 public:
  AtmUser();

  std::string GetLogin() const;
  std::string GetPassword() const;
  int GetCash() const;
  int CreditSum() const;
  double MonthlyPayment() const;
  int CreditTerm() const;

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);
  void SetCash(int cash);
  void SetCreditSum(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetCreditTerm(int months);

  int WithdrawCash(int amount);

  /// new code
  bool IsCreditExist() const;

  /// end of new code

  bool IsNormalLogin();
  bool IsNormalPass();

  void AddCash(int sum_of_cash);

 private:
  CashOperator cash_operator_;
  CreditData credit_data_;
  IdentificationData identification_data_;
};

#endif  // ATM_USER_H
