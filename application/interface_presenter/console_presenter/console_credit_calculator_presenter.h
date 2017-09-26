#ifndef CONSOLE_CREDIT_CALCULATOR_PRESENTER_H
#define CONSOLE_CREDIT_CALCULATOR_PRESENTER_H

#include <calculator_data_handler.h>
#include <console_credit_calculator_menu.h>

class ConsoleCreditCalculatorPresenter {
 public:
  void RunCreditCalculator();

 private:
  void HandleCreditData();

  bool IsCalculationDataValid() const;

  ConsoleCreditCalculatorMenu credit_calculator_menu_;
  CalculatorDataHandler calculator_data_handler_;
};

#endif  // CONSOLE_CREDIT_CALCULATOR_PRESENTER_H
