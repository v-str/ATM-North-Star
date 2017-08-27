#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    ResetManipulationFlags();

    main_menu_.RunMainMenu();

    PerformMenuItem();

    if (user_want_log_out_ || user_want_quit_) {
      break;
    }
  }
}

bool ConsoleMainMenuPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleMainMenuPresenter::PerformMenuItem() {
  if (main_menu_.UserWantAccountInfo()) {
    // run acc info
  }
  if (main_menu_.UserWantRefill()) {
    // run item
  }
  if (main_menu_.UserWantCredit()) {
    // run item
  }
  if (main_menu_.UserWantWithdraw()) {
    // run item
  }
  if (main_menu_.UserWantStatement()) {
    // run item
  }
  if (main_menu_.UserWantLogOut()) {
    // reset user data?
    main_menu_.DisplayLogOutMessage();
    user_want_log_out_ = true;
  }
  if (main_menu_.UserWantQuit()) {
    user_want_quit_ = true;
    // run item
  }
}

void ConsoleMainMenuPresenter::ResetManipulationFlags() {
  user_want_log_out_ = false;
  user_want_quit_ = false;
}
