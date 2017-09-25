#include <console_credit_calculator_presenter.h>

#include <calculator_error_informer.h>

void ConsoleCreditCalculatorPresenter::RunCreditCalculator() {
  credit_calculator_menu_.RunCreditCalculator();

  HandleCreditData();

  if (IsCalculationDataVaild()) {
    // Calculate credit
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

bool ConsoleCreditCalculatorPresenter::IsCalculationDataVaild() const {
  return calculator_data_handler_.IsCalculationDataValid();
}
