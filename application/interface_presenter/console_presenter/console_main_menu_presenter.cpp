#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

#include <console_cash_refill_manager.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    ResetManipulationFlags();

    console_main_menu_.RunMainMenu();

    PerformMenuItem();

    if (user_want_log_out_ || user_want_quit_) {
      break;
    }
  }
}

bool ConsoleMainMenuPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleMainMenuPresenter::PerformMenuItem() {
  if (console_main_menu_.UserWantAccountInfo()) {
    RunAccountInfo();
  }
  if (console_main_menu_.UserWantRefill()) {
    // run item
    ConsoleCashRefillManager refill_manager;
    refill_manager.RunRefillMenu();
  }
  if (console_main_menu_.UserWantCredit()) {
    // run item
  }
  if (console_main_menu_.UserWantWithdraw()) {
    // run item
  }
  if (console_main_menu_.UserWantStatement()) {
    // run item
  }
  if (console_main_menu_.UserWantLogOut()) {
    // reset user data?
    console_main_menu_.DisplayLogOutMessage();
    user_want_log_out_ = true;
  }
  if (console_main_menu_.UserWantQuit()) {
    user_want_quit_ = true;
    // run item
  }
}

void ConsoleMainMenuPresenter::RunAccountInfo() {
  console_account_informer_.SetAccountInfo(AtmInteractor::AccountInfo());
  console_account_informer_.ShowAccountInfo();
  user_want_quit_ = console_account_informer_.UserWantQuit();
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
