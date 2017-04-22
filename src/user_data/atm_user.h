#ifndef ATM_USER_H
#define ATM_USER_H

#include <memory>

#include "cash_operator.h"
#include "user_identifier.h"

class AtmUser {
 public:
  AtmUser();

  std::string GetLogin() const;
  std::string GetPassword() const;
  int GetCash() const;
  int GetCredit() const;
  double GetMonthlyPayment() const;
  int GetAmountOfCreditMonth() const;

  void SetLogin(const std::string& login);
  void SetPassword(const std::string& password);
  void SetCash(int cash);
  void SetCredit(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetAmountOfCreditMonth(int amount_credit_month);

  int WithdrawCash(int amount);

  bool IsCreditAvailable();

  /// new code
  bool IsCreditExist() const;

  /// end of new code

  bool IsNormalLogin();
  bool IsNormalPass();

  void AddCash(int sum_of_cash);
  void AssignAMonthlyPayment(double pay_per_month);

 private:
  std::unique_ptr<CashOperator> cash_operator_;
  std::unique_ptr<UserIdentifier> user_identifier_;
};

#endif  // ATM_USER_H
