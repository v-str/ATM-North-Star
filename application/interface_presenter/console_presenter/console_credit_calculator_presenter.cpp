#include <console_credit_calculator_presenter.h>

void ConsoleCreditCalculatorPresenter::RunCreditCalculator() {
  credit_calculator_menu_.RunCreditCalculator();

  HandleCreditData();

  if (IsCalculationDataVaild()) {
    // Calculate credit
  } else {
    // Get error message from atm core like a
    // credit_calculator_menu.ShowIncorrectInputDataMessage(
    // calculator_data_handler_.GetErrorString);
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
