#ifndef USER_H
#define USER_H

#include "cash_operator.h"
#include "demo_user.h"
#include "initial_screen.h"
#include "refill.h"
#include "statement.h"
#include "statement.h"
#include "system_utility.h"
#include "user_credit.h"
#include "user_identifier.h"
#include "user_input.h"
#include "user_messenger.h"
#include "user_registrator.h"
#include "withdrawal.h"

class Application {
  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
  };

 public:
  void XxX();
  void RunProgram();

 private:
  void DisplayProgramMenu();
  void DoProgramSection(int choice);

  void ShowAccountInfo();
  void RefillOperation();
  void CreditApplication();
  void WithdrawCash();
  void Statement();

  bool is_user_dont_want_to_exit_ = true;

  UserIdentifier user_identifier_;
  CashOperator cash_operator_;
  SystemUtility utility_;
  UserInput user_input_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;
  UserMessenger user_messenger_;
  UserRegistrator registrator_;
  InitialScreen initial_screen_;
  DemoUser demo_mode_;
};

#endif  // USER_H
