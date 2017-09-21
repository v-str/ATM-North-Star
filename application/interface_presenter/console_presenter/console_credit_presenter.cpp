#include <console_credit_presenter.h>

#include <atm_interactor.h>

void ConsoleCreditPresenter::RunCreditMenu() {
  for (;;) {
    ResetManipulationFlag();

    credit_menu_.DisplayCreditMenu();

    PerformMenuItem();

    if (user_want_quit_) {
      break;
    }
  }
}

void ConsoleCreditPresenter::PerformMenuItem() {}

void ConsoleCreditPresenter::ResetManipulationFlag() {
  user_want_quit_ = false;
}
