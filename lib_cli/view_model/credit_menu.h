#ifndef CREDIT_MENU_H
#define CREDIT_MENU_H

class CreditMenu {
 public:
  void RunCreditMenu();

  bool IsUserWantCredit() const;
  bool IsUserWantCreditCalculator() const;
  bool IsUserWantMainMenu() const;
  bool IsUserWantQuit() const;

 private:
  enum CreditItem { kCredit = 1, kCreditCalculator, kMainMenu, kQuit };

  void ProcessUserInput();

  bool IsUserInputContainMenuItem(int user_input);

  void ResetManipulationFlags();

  bool user_want_credit_ = false;
  bool user_want_credit_calculator_ = false;
  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // CREDIT_MENU_H
