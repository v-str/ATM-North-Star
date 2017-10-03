#include <console_credit_calculator_presenter.h>

#include <calculator_error_informer.h>

void ConsoleCreditCalculatorPresenter::RunCreditCalculator() {
  credit_calculator_menu_.RunCreditCalculator();

  HandleCreditData();

  if (IsCalculationDataValid()) {
    CalculateCredit();
    DisplayCreditTable();
  } else {
    credit_calculator_menu_.ShowIncorrectInputError(
        CalculatorErrorInformer::GetErrorsList());
  }
}

void ConsoleCreditCalculatorPresenter::HandleCreditData() {
  calculator_data_handler_.HandleCreditData(
      credit_calculator_menu_.CreditSum(),
      credit_calculator_menu_.CreditInterestRate(),
      credit_calculator_menu_.AmountOfMonths());
}

void ConsoleCreditCalculatorPresenter::CalculateCredit() {
  calculator_.CalculateCredit(calculator_data_handler_.CreditSum(),
                              calculator_data_handler_.InterestRate(),
                              calculator_data_handler_.AmountOfMonth());
}

void ConsoleCreditCalculatorPresenter::DisplayCreditTable() const {
  credit_calculator_menu_.DisplayCreditTable(
      calculator_.AmountOfMonths(), calculator_.MonthlyPayment(),
      calculator_.SumOfOwedCredit(), calculator_.SumOfInterestCharges(),
      calculator_.SumOfMainDebtPayments());
  credit_calculator_menu_.DisplayTotalLine(calculator_.TotalMonthlyPayment(),
                                           calculator_.TotalInterestCharges(),
                                           calculator_.TotalMainDebtPayment());
}

bool ConsoleCreditCalculatorPresenter::IsCalculationDataValid() const {
  return calculator_data_handler_.IsCalculationDataValid();
}
