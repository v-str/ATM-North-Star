#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

#include <cash_operation_validator.h>
#include <console_account_informer.h>
#include <console_cash_refill_manager.h>
#include <console_withdrawal_manager.h>

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
    RunRefillManager();
  }
  if (console_main_menu_.UserWantCredit()) {
    // run item
  }
  if (console_main_menu_.UserWantWithdraw()) {
    // run item
    ConsoleWithdrawalManager withdrawal_manager;
    withdrawal_manager.ShowWithdrawNotification();
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
  ConsoleAccountInformer console_account_informer_;
  console_account_informer_.SetAccountInfo(AtmInteractor::AccountInfo());
  console_account_informer_.ShowAccountInfo();
  user_want_quit_ = console_account_informer_.UserWantQuit();
}

void ConsoleMainMenuPresenter::RunRefillManager() {
  ConsoleCashRefillManager refill_manager;
  refill_manager.RunRefillMenu();

  if (CashOperationValidator::IsRefillingCorrect(refill_manager.SumOfCash())) {
    AtmInteractor::RefillCash(refill_manager.SumOfCash());
    refill_manager.ShowCorrectRefillingNotification();
  } else {
    refill_manager.ShowIncorrectRefillingNotification();
  }

  user_want_quit_ = refill_manager.UserWantQuit();
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
