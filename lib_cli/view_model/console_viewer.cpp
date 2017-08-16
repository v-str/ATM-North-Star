#include <console_viewer.h>

void ConsoleViewer::RunApplication() {
  initial_menu_.DisplaySplashScreen();
  for (;;) {
    user_want_exit_ = false;
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());
    if (user_want_exit_) {
      initial_menu_.DisplayFarewellMessage();
      break;
    }
  }
}

void ConsoleViewer::RunSubMenu(int sub_menu) {
  if (sub_menu == ConsoleInitialMenu::kLoginMenu) {
    login_menu_.RunLoginMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kRegistrationMenu) {
    RunRegistrationMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kDemoMenu) {
    RunDescriptionMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kExit) {
    user_want_exit_ = true;
  }
}

void ConsoleViewer::RunDescriptionMenu() {
  description_menu_.RunDescriptionMenu();
  if (description_menu_.IsUserWantToExitProgram()) {
    user_want_exit_ = true;
  }
}

void ConsoleViewer::RunRegistrationMenu() {
  registration_menu_.RunRegistrationMenu();
  // user_want_to_exit_ = registration_menu.UserWantToExitProgram();
}
