#include <console_initial_presenter.h>

#include <string>

void ConsoleInitialPresenter::RunApplication() {
  initial_menu_.RunSplashScreen();
  while (!user_want_to_exit_) {
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());
  }
  initial_menu_.DisplayFarewellMessage();
}

void ConsoleInitialPresenter::RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu) {
  switch (sub_menu) {
    case ConsoleInitialMenu::kLoginMenu:
      login_menu_.RunLoginMenu();
      break;
    case ConsoleInitialMenu::kRegistrationMenu:
      RunRegistrationMenu();
      break;
    case ConsoleInitialMenu::kDescriptionMenu:
      RunDescriptionMenu();
      break;
    case ConsoleInitialMenu::kExit:
      user_want_to_exit_ = true;
      break;
    default:
      break;
  }
}

void ConsoleInitialPresenter::RunDescriptionMenu() {
  description_menu_.RunDescriptionMenu();
  if (description_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}

void ConsoleInitialPresenter::RunRegistrationMenu() {
  registration_menu_.RunRegistrationMenu();
  if (registration_menu_.IsUserWantToRegistrate()) {
    registration_menu_.ReceiveRegistrationDataFromUser();
    std::string login = registration_menu_.LoginString();
    std::string password = registration_menu_.PasswordString();

    // pass here data for atm_model

  } else if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}
