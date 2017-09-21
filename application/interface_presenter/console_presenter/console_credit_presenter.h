#ifndef CONSOLE_CREDIT_PRESENTER_H
#define CONSOLE_CREDIT_PRESENTER_H

#include <credit_menu.h>

class ConsoleCreditPresenter {
 public:
  void RunCreditMenu();

 private:
  CreditMenu credit_menu;
};

#endif  // CONSOLE_CREDIT_PRESENTER_H
