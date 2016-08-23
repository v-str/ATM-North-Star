#ifndef USER_H
#define USER_H

#include <string>

class AtmUser {
  using string = std::string;

 public:
  AtmUser();
  AtmUser(const string &login, const string &password, double cash, long credit,
          double monthly_payment, int amount_of_credit_month);

  void Registration();

  bool IsNormalLogin() const;
  bool IsNormalPass() const;
  bool AlreadyHasACredit() const;
  bool IsNormalWithdrawal(double cash_sum) const;

  bool Refill();
  bool Statement();
  bool ShowAccountInfo();
  bool ConsiderACredit();
  bool Withdrawal();

  void ShowIncorrectDataMessage();
  void ShowExitMessage();
  void MonthToRepay();
  void WishGoodDay();

 private:
  void RunProgramUntilUserWantToExit();
  bool RunProgram();
  bool HandleUserChoice(int choice);

  void SetupProgram();
  void ClearScreen();
  void ShowTransactionMenu();
  void RefuseACredit();

  bool IndividualCreditCalculation();

  bool ConsiderACreditBasedOnCash();

  bool SuggestUserToExitWithDefaultMenu();
  bool SuggestUserToExitWithIncorrectDataMenu();
  bool SuggestUserToExitWithConfirmationMenu();

  bool CreditApplication();
  bool RefuseToReCredit();
  bool GiveACredit();
  bool MaxCreditCalculation(double max_sum);

  bool IsUserWantToExit(const string &menu_text, const string &choice_text);
  int GetUserChoice(const string &choice_text) const;
  int GetChoiceFromUser() const;
  int GetUserChoiceWithMenuText(const string &menu_text,
                                const string &choice_text) const;
  void WriteTextWithDelay(const string &text) const;
  void WriteSymbolsNTimes(char symbol, int n) const;

  string login_ = "no_name";
  string password_ = "0000";
  double cash_ = 0.0;
  double credit_ = 0.0;
  double monthly_payment_ = 0.0;
  int amount_of_credit_month_ = 0;
};

#endif  // USER_H
