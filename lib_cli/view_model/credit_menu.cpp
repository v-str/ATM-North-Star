#include <credit_menu.h>

#include <credit_messenger.h>

void CreditMenu::DisplayCreditMenu() { CreditMessenger::DisplayCreditMenu(); }

bool CreditMenu::IsUserWantCredit() const {}

bool CreditMenu::IsUserWantCreditCalculator() const {}

bool CreditMenu::IsUserWantMainMenu() const {}

bool CreditMenu::IsUserWantQuit() const {}
