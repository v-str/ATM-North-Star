#ifndef CONSOLE_CREDIT_PRESENTER_H
#define CONSOLE_CREDIT_PRESENTER_H

#include <calculator_data_handler.h>
#include <console_credit_calculator_menu.h>
#include <console_credit_menu.h>

class ConsoleCreditPresenter {
 public:
  void RunCreditMenu();

  bool UserWantQuit() const;

 private:
  void PerformMenuItem();
  void RunCreditCalculator();
  void HandleCreditData();
  void ResetManipulationFlag();

  bool IsCreditDataOk() const;

  ConsoleCreditMenu credit_menu_;
  ConsoleCreditCalculatorMenu credit_calculator_menu_;
  CalculatorDataHandler calculator_data_handler_;

  bool user_want_quit_ = false;
  bool user_want_main_menu_ = false;
};

#endif  // CONSOLE_CREDIT_PRESENTER_H
