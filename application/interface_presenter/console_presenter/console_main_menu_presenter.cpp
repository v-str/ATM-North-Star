#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

#include <cash_operation_validator.h>
#include <console_account_menu.h>
#include <console_refill_menu.h>
#include <console_withdrawal_presenter.h>
#include <statement_menu.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    ResetManipulationFlags();

    console_main_menu_.RunMainMenu();

    PerformMenuItem();

    if (user_want_log_out_ || user_want_quit_) {
      if (user_want_log_out_) {
        AtmInteractor::ResetData();
      }
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
    RunRefillManager();
  }
  if (console_main_menu_.UserWantCredit()) {
    // run item
  }
  if (console_main_menu_.UserWantWithdraw()) {
    RunWithdrawalManager();
  }
  if (console_main_menu_.UserWantStatement()) {
    RunStatementManager();
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
  ConsoleAccountMenu console_account_menu_;
  console_account_menu_.SetAccountInfo(AtmInteractor::AccountInfo());
  console_account_menu_.ShowAccountInfo();
  user_want_quit_ = console_account_menu_.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunRefillManager() {
  ConsoleRefillMenu refill_menu;
  refill_menu.RunRefillMenu();

  if (CashOperationValidator::IsRefillingCorrect(refill_menu.SumOfCash())) {
    AtmInteractor::RefillCash(refill_menu.SumOfCash());
    refill_menu.ShowCorrectRefillingNotification();
  } else {
    refill_menu.ShowIncorrectRefillingNotification();
  }

  user_want_quit_ = refill_menu.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunWithdrawalManager() {
  ConsoleWithdrawalPresenter withdrawal_presenter;
  withdrawal_presenter.RunWithdrawalMenu();
  user_want_quit_ = withdrawal_presenter.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunStatementManager() {
  StatementMenu statement_menu;
  statement_menu.RunStatement(AtmInteractor::Cash());
  user_want_quit_ = statement_menu.UserWantQuit();
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
