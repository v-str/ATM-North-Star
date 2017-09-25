#ifndef CONSOLE_CREDIT_PRESENTER_H
#define CONSOLE_CREDIT_PRESENTER_H

#include <console_credit_calculator_presenter.h>
#include <console_credit_menu.h>

class ConsoleCreditPresenter {
 public:
  void RunCreditMenu();

  bool UserWantQuit() const;

 private:
  void PerformMenuItem();
  void RunCreditCalculator();
  void ResetManipulationFlag();

  ConsoleCreditCalculatorPresenter console_credit_calculator_presenter_;
  ConsoleCreditMenu credit_menu_;

  bool user_want_quit_ = false;
  bool user_want_main_menu_ = false;
};

#endif  // CONSOLE_CREDIT_PRESENTER_H
