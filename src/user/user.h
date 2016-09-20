#ifndef USER_H
#define USER_H

#include <string>

#include "cash_operator.h"
#include "notice_about_error.h"
#include "notice_about_successful_action.h"
#include "refill.h"
#include "statement.h"
#include "statement.h"
#include "system_utility.h"
#include "user_credit.h"
#include "user_identifier.h"
#include "user_input.h"
#include "user_messenger.h"
#include "withdrawal.h"

class User {
  using string = std::string;
  enum MenuSection {
    kAccountSection = 1,
    kRefillSection,
    kCreditSection,
    kWidthdrawalSection,
    kStatementSection,
    kExitSection,
  };

 public:
  User() {}
  User(const string &login, const string &password, double cash, int credit,
       double monthly_payment, int amount_of_credit_month);

  void Registration();

 private:
  void RunProgramUntilUserWantToExit();
  bool RunProgram();
  bool HandleUserChoice(int choice);

  bool ShowAccountInfo();
  bool RefillOperation();
  bool CreditApplication();
  bool WithdrawCash();
  bool Statement();

  UserIdentifier user_identifier_;
  CashOperator cash_operator_;
  UserMessenger user_messenger_;
  NoticeAboutError error_message_;
  NoticeAboutSuccessfulAction successful_action_;
  SystemUtility utility_;
  UserInput user_input_;
  Refill refill_;
  UserCredit user_credit_;
  Withdrawal withdrawal_;
  UserStatement statement_;
};

#endif  // USER_H
