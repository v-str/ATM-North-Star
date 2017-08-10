#ifndef ATM_USER_H
#define ATM_USER_H

#include <memory>

#include "cash_operator.h"
#include "credit_data.h"
#include "identification_data.h"

class AtmUser {
 public:
  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);
  void SetCash(int cash);
  void SetCreditData(const CreditData& credit_data);

  std::string Login() const;
  std::string Password() const;
  int Cash() const;
  int CreditSum() const;
  double MonthlyPayment() const;
  int CreditTerm() const;

  bool IsCreditExist() const;
  bool IsNormalLogin() const;
  bool IsNormalPass() const;

  void AddCash(int sum_of_cash);
  int WithdrawCash(int amount);

 private:
  CashOperator cash_operator_;
  CreditData credit_data_;
  IdentificationData identification_data_;
};

#endif  // ATM_USER_H
