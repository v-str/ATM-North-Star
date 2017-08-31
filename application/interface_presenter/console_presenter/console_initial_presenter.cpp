#include <console_initial_presenter.h>

#include <string>

void ConsoleInitialPresenter::RunApplication() {
  initial_menu_.RunSplashScreen();
  while (!user_want_to_quit_) {
    ResetManipulationFlags();

    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());
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
  if (description_menu_.IsUserWantToExitProgram()) {
    user_want_to_quit_ = true;
  }
}

void ConsoleInitialPresenter::RunRegistrationMenu() {
  registration_presenter_.RunRegistrationMenu();
  user_want_to_quit_ = registration_presenter_.UserWantQuit();
}

void ConsoleInitialPresenter::ResetManipulationFlags() {
  user_want_to_quit_ = false;
}
