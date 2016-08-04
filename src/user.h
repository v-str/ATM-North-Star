#ifndef USER_H
#define USER_H

#include <string>

class AtmUser {
  using string = std::string;

 public:
  AtmUser();
  AtmUser(const string &login, const string &password, double cash, long credit,
          double monthly_payment, int amount_of_credit_month);

  bool IsNormalLogin() const;
  bool IsNormalPass() const;
  bool IsCreditEmpty() const;
  bool IsNormalWithdrawal(double cash_sum) const;

  void MainMenuError();
  void ClearScreen();
  void Write(const string &s);
  void ErrorReload();
  void ExitToMain();
  void MaxCreditCalculation(double max_sum);
  void IndividualCreditCalculation();
  void Exit();
  void MonthToRepay();

  void TransactionMenu();
  void Registration();
  void ShowAccInfo();
  void Refill();
  void CreditApp();
  void Withdrawal();
  void Statement();

  void DemoMode();
  void DemoAccInfo();
  void DemoRefill();
  void DemoExit();
  void DemoCreditApp();
  void DemoWidthdrawal();
  void DemoStatement();

 private:
  string login_ = "no_name";
  string password_ = "0000";
  double cash_ = 0.0;
  double credit_ = 0.0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;
};

#endif  // USER_H
