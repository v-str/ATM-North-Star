#include <console_main_menu_presenter.h>

#include <atm_interactor.h>

void ConsoleMainMenuPresenter::RunMainMenu() {
  for (;;) {
    main_menu_.RunMainMenu();

    if (main_menu_.UserWantLogOut()) {
      main_menu_.DisplayLogOutMessage();
      // reset user data?
      break;
    }
    if (main_menu_.UserWantQuit()) {
      user_want_quit_ = true;
      break;
    }
  }
}

bool ConsoleMainMenuPresenter::UserWantQuit() const { return user_want_quit_; }

void ConsoleMainMenuPresenter::PerformMenuItem() {}
