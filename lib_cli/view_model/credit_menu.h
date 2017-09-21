#ifndef CREDIT_MENU_H
#define CREDIT_MENU_H

class CreditMenu {
 public:
  void DisplayCreditMenu();

  bool IsUserWantCredit() const;
  bool IsUserWantCreditCalculator() const;
  bool IsUserWantMainMenu() const;
  bool IsUserWantQuit() const;

 private:
  void ProcessUserInput();

  bool user_want_credit_ = false;
  bool user_want_credit_calculator_ = false;
  bool user_want_main_menu_ = false;
  bool user_want_quit_ = false;
};

#endif  // CREDIT_MENU_H
