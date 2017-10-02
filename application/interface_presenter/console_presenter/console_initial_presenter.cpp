#include <console_initial_presenter.h>

#include <string>

void ConsoleInitialPresenter::RunApplication() {
  initial_menu_.RunSplashScreen();

  for (;;) {
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());

    if (user_want_to_quit_) {
      break;
    }
  }

  initial_menu_.DisplayFarewellMessage();
}

void ConsoleInitialPresenter::RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu) {
  switch (sub_menu) {
    case ConsoleInitialMenu::kLoginMenu:
      RunLoginMenu();
      break;
    case ConsoleInitialMenu::kRegistrationMenu:
      RunRegistrationMenu();
      break;
    case ConsoleInitialMenu::kDescriptionMenu:
      RunDescriptionMenu();
      break;
    case ConsoleInitialMenu::kQuit:
      user_want_to_quit_ = true;
      break;
    default:
      break;
  }
}

void ConsoleInitialPresenter::RunLoginMenu() { login_menu_.RunLoginMenu(); }

void ConsoleInitialPresenter::RunDescriptionMenu() {
  description_menu_.RunDescriptionMenu();
  user_want_to_quit_ = description_menu_.IsUserWantToExitProgram();
}

void ConsoleInitialPresenter::RunRegistrationMenu() {
  registration_presenter_.RunRegistrationMenu();
  user_want_to_quit_ = registration_presenter_.UserWantQuit();
}
