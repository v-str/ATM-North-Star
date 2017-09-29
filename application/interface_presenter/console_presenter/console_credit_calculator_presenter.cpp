#include <console_credit_calculator_presenter.h>

#include <calculator.h>
#include <calculator_error_informer.h>

#include <console_editor.h>

#include <iostream>

void ConsoleCreditCalculatorPresenter::RunCreditCalculator() {
  credit_calculator_menu_.RunCreditCalculator();

  HandleCreditData();

  if (IsCalculationDataValid()) {
    Calculator::CalculateCredit(calculator_data_handler_.CreditSum(),
                                calculator_data_handler_.InterestRate(),
                                calculator_data_handler_.AmountOfMonth());

    //    ConsoleEditor::WriteText("\n\nMonthly credit payment: ");
    //    std::cout << Calculator::MonthlyPayment();
    //    ConsoleEditor::AddEmptyLineNTimes(3);
    //    ConsoleEditor::IgnoreCinLine();
    // credit_calculator_menu_.ShowCreditTable(params);
  } else {
    credit_calculator_menu_.ShowIncorrectInputError(
        CalculatorErrorInformer::GetErrorsList());
  }
}

void ConsoleCreditCalculatorPresenter::HandleCreditData() {
  calculator_data_handler_.HandleData(
      credit_calculator_menu_.CreditSum(),
      credit_calculator_menu_.CreditInterestRate(),
      credit_calculator_menu_.AmountOfMonths());
}

bool ConsoleCreditCalculatorPresenter::IsCalculationDataValid() const {
  return calculator_data_handler_.IsCalculationDataValid();
}
