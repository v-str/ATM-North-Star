#include <credit_menu.h>

#include <credit_messenger.h>

void CreditMenu::DisplayCreditMenu() {
  CreditMessenger::DisplayCreditMenu();
  ProcessUserInput();
}

bool CreditMenu::IsUserWantCredit() const { return user_want_credit_; }

bool CreditMenu::IsUserWantCreditCalculator() const {
  return user_want_credit_calculator_;
}

bool CreditMenu::IsUserWantMainMenu() const { return user_want_main_menu_; }

bool CreditMenu::IsUserWantQuit() const { return user_want_quit_; }

void CreditMenu::ProcessUserInput() {}
