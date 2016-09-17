#ifndef USER_H
#define USER_H

#include <string>
#include "cash_operator.h"
#include "notice_about_error.h"
#include "notice_about_successful_action.h"
#include "system_utility.h"
#include "user_credit.h"
#include "user_identifier.h"
#include "user_input.h"
#include "user_messenger.h"
#include "withdrawal/withdrawal.h"

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
  void WishGoodDay();

 private:
  void RunProgramUntilUserWantToExit();

  void SetupProgram();  // TODO problem with name of method

  bool RunProgram();
  bool HandleUserChoice(int choice);

  bool ShowAccountInfo();

  bool Refill();
  bool CreditApplication();

  bool WithdrawCash();
  bool Statement();

  void ShowTransactionMenu();

  void ShowIncorrectDataMessage();

  bool SuggestUserToExitWithConfirmationMenu();

  int GetUserChoice(const string &choice_text) const;

  int GetChoiceFromUser() const;

  int GetUserChoiceWithMenuText(const string &menu_text,
                                const string &choice_text) const;
  void WriteTextWithDelay(const string &text) const;

  void WriteSymbolsNTimes(char symbol, int n) const;

  int NumberOfDigits(int cash) const;

  string GetSpaces(int convertation_cash_to_space) const;

  UserInput user_input_;
  SystemUtility utility_;
  UserMessenger user_messenger_;
  UserCredit user_credit_;
  NoticeAboutError error_message_;
  NoticeAboutSuccessfulAction successful_action_;
  UserIdentifier user_identifier_;
  CashOperator cash_operator_;
  Withdrawal withdrawal_;
};

#endif  // USER_H
