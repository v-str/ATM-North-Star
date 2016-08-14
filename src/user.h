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
  bool AlreadyHasACredit() const;
  bool IsNormalWithdrawal(double cash_sum) const;

  void ShowIncorrectDataMessage();

  void ShowExitMessage();
  void MonthToRepay();

  void Registration();
  bool ShowAccInfo();

  bool Refill();
  bool Statement();

  bool ConsiderACredit();
  bool Withdrawal();

  void DemoMode();
  void DemoAccInfo();
  void DemoRefill();
  void DemoExit();
  void DemoCreditApp();
  void DemoWidthdrawal();
  void DemoStatement();

  void RunProgramUntilUserWantToExit();

 private:
  void SetupProgram();
  void ClearScreen();

  bool RunProgram();
  void ShowTransactionMenu();
  bool HandleUserChoice(int choice);
  bool IndividualCreditCalculation();

  void WishGoodDay();
  bool ConsiderACreditBasedOnCash();

  bool SuggestUserToExitWithDefaultMenu();
  bool SuggestUserToExitWithIncorrectDataMenu();
  bool SuggestUserToExitWithConfirmationMenu();

  bool CreditApplication();
  bool RefuseToReCredit();
  bool GiveACredit();
  void RefuseACredit();
  bool MaxCreditCalculation(double max_sum);

  bool SuggestUserToExit(const string &menu_text, const string &choice_text);
  bool IsUserWantToExit(const string &menu_text, const string &choice_text);
  int GetUserChoice(const string &choice_text) const;
  int GetValueFromUser() const;
  int GetUserChoiceWithMenuText(const string &menu_text,
                                const string &choice_text) const;
  void WriteTextWithDelay(const string &text) const;

  string login_ = "no_name";
  string password_ = "0000";
  double cash_ = 0.0;
  double credit_ = 0.0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;
};

#endif  // USER_H
