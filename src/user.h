#ifndef USER_H
#define USER_H

#include <string>
#include "account_info.h"
#include "identification_of_user.h"
#include "system_utility.h"
#include "user_credit.h"
#include "user_input.h"
#include "user_messanger.h"
#include "notice_about_error.h"

class AtmUser {
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
  AtmUser() {}
  AtmUser(const string &login, const string &password, double cash, int credit,
          double monthly_payment, int amount_of_credit_month);

  void Registration();
  void WishGoodDay();

 private:
  bool Refill();
  bool Statement();
  bool ShowAccountInfo();
  bool ConsiderACredit();
  bool WithdrawCash();

  void RunProgramUntilUserWantToExit();
  bool RunProgram();
  bool HandleUserChoice(int choice);

  void InitialRegistrationScreen();
  void SetupProgram();

  void MonthToRepay();

  void ShowTransactionMenu();

  void ShowIncorrectDataMessage();
  void WithdrawFromAccount(int sum_of_withdrawal);

  bool RefuseACredit();

  bool IndividualCreditCalculation(int maximal_sum_of_credit);

  bool ConsiderACreditBasedOnCash();

  bool SuggestUserToExitWithConfirmationMenu();

  bool CreditApplication();
  bool RefuseToGrantAnotherCredit();
  bool GiveACredit();
  bool ExitCreditMenu();
  bool ReloadProgram();

  int GetCreditMonths();

  bool AlreadyHasACredit() const;
  bool IsWithdrawalAcceptable(double cash_sum) const;

  bool IsCorrectPassword(const string &password);

  bool MaxCreditCalculation(int maximal_sum_of_credit);
  bool EnrollACredit(double max_sum, double pay_per_month);
  bool RepealACredit();

  int GetUserChoice(const string &choice_text) const;
  int GetChoiceFromUser() const;
  int GetUserChoiceWithMenuText(const string &menu_text,
                                const string &choice_text) const;
  void WriteTextWithDelay(const string &text) const;
  void WriteSymbolsNTimes(char symbol, int n) const;
  int NumberOfDigits(int cash) const;

  int SumOfWithdrawal() const;

  string GetSpaces(int cash_) const;

  AccountInfo account_info_;

  UserInput user_input_;
  SystemUtility utility_;
  UserMessanger user_messanger_;
  UserCredit user_credit_;
  IdentificationOfUser identification_of_user_;
  NoticeAboutError error_;
};

#endif  // USER_H
