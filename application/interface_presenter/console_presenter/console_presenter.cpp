#include <console_presenter.h>

#include <string>

void ConsolePresenter::RunApplication() {
  initial_menu_.RunSplashScreen();
  while (!user_want_to_exit_) {
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());
  }
  initial_menu_.DisplayFarewellMessage();
}

void ConsolePresenter::RunSubMenu(ConsoleInitialMenu::SubMenu sub_menu) {
  if (sub_menu == ConsoleInitialMenu::kLoginMenu) {
    login_menu_.RunLoginMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kRegistrationMenu) {
    RunRegistrationMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kDescriptionMenu) {
    RunDescriptionMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kExit) {
    user_want_to_exit_ = true;
  }
}

void ConsolePresenter::RunDescriptionMenu() {
  description_menu_.RunDescriptionMenu();
  if (description_menu_.IsUserWantToExitProgram()) {
    user_want_to_exit_ = true;
  }
}

void ConsolePresenter::RunRegistrationMenu() {
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
