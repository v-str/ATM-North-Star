#ifndef USER_H
#define USER_H

#include <string>
#include "user_input.h"
#include "system_utility.h"
#include "user_messanger.h"
#include "user_parameters.h"

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
  AtmUser(const string &login, const string &password, double cash, long credit,
          double monthly_payment, int amount_of_credit_month);

  void Registration();

  void GetPassword();
  void GetLogin();

  bool IsNormalLogin() const;
  bool IsNormalPass() const;
  bool AlreadyHasACredit() const;
  bool IsWithdrawalAcceptable(double cash_sum) const;

  bool Refill();
  bool Statement();
  bool ShowAccountInfo();
  bool ConsiderACredit();
  bool WithdrawCash();

  void ShowIncorrectDataMessage();

  void MonthToRepay();
  void WishGoodDay();

  void InitialRegistrationScreen();
  void NoticeAboutSuccessfulRegistration();
  void NoticeAboutIncorrectLogin();
  void NoticeAboutIncorrectPassword();


 private:
  void RunProgramUntilUserWantToExit();
  bool RunProgram();
  bool HandleUserChoice(int choice);

  void SetupProgram();

  void ShowTransactionMenu();

  void WithdrawFromAccount(int sum_of_withdrawal);

  bool RefuseACredit();

  bool IndividualCreditCalculation();

  bool ConsiderACreditBasedOnCash();

  bool SuggestUserToExitWithConfirmationMenu();

  bool CreditApplication();
  bool RefuseToReCredit();
  bool GiveACredit();
  bool ExitCreditMenu();
  bool ReloadProgram();

  bool UnacceptableAmountOfMonths();

  bool IsCorrectPassword(const string &password);

  bool MaxCreditCalculation(double max_sum);
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

};

#endif  // USER_H
