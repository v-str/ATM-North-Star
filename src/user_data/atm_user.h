#ifndef ATMUSER_H
#define ATMUSER_H

#include <memory>

#include "cash_operator.h"
#include "user_identifier.h"

class AtmUser {
 public:
  AtmUser();

  std::string get_login() const;
  std::string get_password() const;
  int get_cash() const;
  int get_credit() const;
  double get_monthly_payment() const;
  int get_amount_of_credit_month() const;

  void set_login(const std::string &login);
  void set_password(const std::string &password);
  void set_cash(int cash);
  void set_credit(int credit);
  void set_monthly_payment(double monthly_payment);
  void set_amount_of_credit_month(int amount_credit_month);

  int get_assigned_credit(int sum_of_credit);
  int withdraw_cash(int amount);

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
