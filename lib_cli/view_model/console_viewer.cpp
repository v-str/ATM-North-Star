#include <console_viewer.h>

void ConsoleViewer::RunApplication() {
  initial_menu_.DisplaySplashScreen();
  for (;;) {
    initial_menu_.RunInitialMenu();
    RunSubMenu(initial_menu_.GetSubMenu());
    if (user_want_exit_) {
      initial_menu_.DisplayFarewellMessage();
      break;
    }
  }
}

void ConsoleViewer::RunDescriptionMenu() {
  description_menu_.RunDescriptionMenu();
  user_want_exit_ = description_menu_.UserWantToExitProgram();
}

void ConsoleViewer::RunSubMenu(int sub_menu) {
  if (sub_menu == ConsoleInitialMenu::kLoginMenu) {
    login_menu_.RunLoginMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kRegistrationMenu) {
    registration_menu_.RunRegistrationMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kDemoMenu) {
    RunDescriptionMenu();
  }
  if (sub_menu == ConsoleInitialMenu::kExit) {
    user_want_exit_ = true;
  }
}
