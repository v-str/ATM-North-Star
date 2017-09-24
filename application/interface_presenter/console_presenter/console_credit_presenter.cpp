#include <console_credit_presenter.h>

#include <atm_interactor.h>

#include <console_editor.h>

#include <iostream>

void ConsoleCreditPresenter::RunCreditMenu() {
  for (;;) {
    ResetManipulationFlag();

    credit_menu_.RunCreditMenu();

    PerformMenuItem();

    if (user_want_quit_ || user_want_main_menu_) {
      break;
    }
  }
}

bool ConsoleCreditPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleCreditPresenter::PerformMenuItem() {
  if (credit_menu_.IsUserWantCredit()) {
    // run credit menu
  }
  if (credit_menu_.IsUserWantCreditCalculator()) {
    RunCreditCalculator();
  }
  if (credit_menu_.IsUserWantMainMenu()) {
    user_want_main_menu_ = true;
  }
  if (credit_menu_.IsUserWantQuit()) {
    user_want_quit_ = true;
  }
}

void ConsoleCreditPresenter::RunCreditCalculator() {
  credit_calculator_menu_.RunCreditCalculator();

  HandleCreditData();

  if (IsCreditDataOk()) {
    ConsoleEditor::WriteText("\nCREDIT DATA OK\n\n");

    std::cout << "Credit sum: " << std::boolalpha
              << calculator_data_handler_.IsCreditDataValid() << " "
              << calculator_data_handler_.CreditSum() << "\n"
              << "Interest rate: " << std::boolalpha
              << calculator_data_handler_.IsCreditInterestRateValid() << " "
              << calculator_data_handler_.InterestRate() << "\n"
              << "Amount of months: " << std::boolalpha
              << calculator_data_handler_.IsAmountOfCreditValid() << " "
              << calculator_data_handler_.AmountOfMonth() << "\n\n";

    ConsoleEditor::IgnoreCinLine();
  } else {
    ConsoleEditor::WriteText("\n\nERROR CREDIT DATA\n\n");

    std::cout << "Credit sum: " << std::boolalpha
              << calculator_data_handler_.IsCreditDataValid() << " "
              << calculator_data_handler_.CreditSum() << "\n"
              << "Interest rate: " << std::boolalpha
              << calculator_data_handler_.IsCreditInterestRateValid() << " "
              << calculator_data_handler_.InterestRate() << "\n"
              << "Amount of months: " << std::boolalpha
              << calculator_data_handler_.IsAmountOfCreditValid() << " "
              << calculator_data_handler_.AmountOfMonth() << "\n\n";

    ConsoleEditor::IgnoreCinLine();
  }
}

void ConsoleCreditPresenter::HandleCreditData() {
  calculator_data_handler_.HandleData(
      credit_calculator_menu_.CreditSum(),
      credit_calculator_menu_.CreditInterestRate(),
      credit_calculator_menu_.AmountOfMonths());
}

void ConsoleCreditPresenter::ResetManipulationFlag() {
  user_want_quit_ = false;
  user_want_main_menu_ = false;
}

bool ConsoleCreditPresenter::IsCreditDataOk() const {
  if (calculator_data_handler_.IsCreditDataValid() &&
      calculator_data_handler_.IsCreditInterestRateValid() &&
      calculator_data_handler_.IsAmountOfCreditValid()) {
    return true;
  }
  return false;
}
