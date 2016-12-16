#ifndef ATMUSER_H
#define ATMUSER_H

#include "cash_operator.h"
#include "user_identifier.h"

#include <memory>

class AtmUser {
 public:
  AtmUser();

  void SetLogin(const std::string &login);
  void SetPassword(const std::string &password);
  void SetCash(int cash);
  void SetCredit(int credit);
  void SetMonthlyPayment(double monthly_payment);
  void SetAmountOfCreditMonth(int amount_credit_month);

  std::string GetLogin() const;
  std::string GetPassword() const;

  int GetCash() const;
  int GetCredit() const;
  double GetMonthlyPayment() const;
  int GetAmountOfCreditMonth() const;
  int GetAssignACredit(int sum_of_credit);
  int WithdrawCashFromUser(int amount);

  bool IsCreditAvailable();
  bool IsNormalLogin();
  bool IsNormalPass();

  void AddCash(int sum_of_cash);
  void AssignAMonthlyPayment(double pay_per_month);


 private:
  std::unique_ptr<CashOperator> cash_operator_;
  std::unique_ptr<UserIdentifier> user_identifier_;
};

#endif  // ATMUSER_H
