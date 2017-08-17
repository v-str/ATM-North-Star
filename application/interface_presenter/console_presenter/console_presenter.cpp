#include <console_presenter.h>

void ConsolePresenter::RunApplication() {
  console_viewer_.DisplaySplashScreen();
  while (!console_viewer_.IsUserWantToExit()) {
    console_viewer_.RunInitialMenu();
  }
  console_viewer_.DisplayFarewellMessage();
}
