#include <console_viewer.h>

void ConsoleViewer::DisplaySplashScreen() {
  initial_menu_.DisplaySplashScreen();
}

void ConsoleViewer::RunInitialMenu() {
  initial_menu_.RunInitialMenu();
  RunSubMenu(initial_menu_.GetSubMenu());
}

void ConsoleViewer::DisplayFarewellMessage() {
  initial_menu_.DisplayFarewellMessage();
}

bool ConsoleViewer::IsUserWantToExit() { return user_want_exit_; }

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
  if (registration_menu_.IsUserWantToRegistrate()) {
    registration_menu_.ReceiveRegistrationDataFromUser();
  } else if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_exit_ = true;
  }
}
