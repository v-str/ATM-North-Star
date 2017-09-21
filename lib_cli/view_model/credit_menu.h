#ifndef CREDIT_MENU_H
#define CREDIT_MENU_H

class CreditMenu {
 public:
  void DisplayCreditMenu();

  bool IsUserWantCredit() const;
  bool IsUserWantCreditCalculator() const;
  bool IsUserWantMainMenu() const;
  bool IsUserWantQuit() const;
};

#endif  // CREDIT_MENU_H
