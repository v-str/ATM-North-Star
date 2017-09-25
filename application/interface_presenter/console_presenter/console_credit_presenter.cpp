#include <console_credit_presenter.h>

#include <atm_interactor.h>

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
  console_credit_calculator_presenter_.RunCreditCalculator();
}

void ConsoleCreditPresenter::ResetManipulationFlag() {
  user_want_quit_ = false;
  user_want_main_menu_ = false;
}
