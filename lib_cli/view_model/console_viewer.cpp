#include <console_viewer.h>

void ConsoleViewer::DisplaySplashScreen() { initial_menu_.RunSplashScreen(); }

void ConsoleViewer::RunInitialMenu() {
  initial_menu_.RunInitialMenu();
  RunSubMenu(initial_menu_.GetSubMenu());
}

void ConsoleViewer::DisplayFarewellMessage() {
  initial_menu_.DisplayFarewellMessage();
}

std::string ConsoleViewer::LoginString() const {
  return registration_menu_.LoginString();
}

std::string ConsoleViewer::PasswordString() const {
  return registration_menu_.PasswordString();
}

bool ConsoleViewer::IsUserWantToExit() const { return user_want_exit_; }

bool ConsoleViewer::IsRegistrationDataReceived() const {
  return is_registration_data_received_;
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
  if (registration_menu_.IsUserWantToRegistrate()) {
    registration_menu_.ReceiveRegistrationDataFromUser();
    is_registration_data_received_ = true;
  } else if (registration_menu_.IsUserWantToExitProgram()) {
    user_want_exit_ = true;
  }
}
