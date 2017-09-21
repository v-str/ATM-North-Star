#ifndef CONSOLE_CREDIT_PRESENTER_H
#define CONSOLE_CREDIT_PRESENTER_H

#include <credit_menu.h>

class ConsoleCreditPresenter {
 public:
  void RunCreditMenu();

  bool UserWantQuit() const;

 private:
  void PerformMenuItem();
  void ResetManipulationFlag();

  CreditMenu credit_menu_;

  bool user_want_quit_ = false;
};

#endif  // CONSOLE_CREDIT_PRESENTER_H
