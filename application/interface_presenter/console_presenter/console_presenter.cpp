#include <console_presenter.h>

#include <string>

void ConsolePresenter::RunApplication() {
  console_viewer_.DisplaySplashScreen();
  while (!console_viewer_.IsUserWantToExit()) {
    console_viewer_.RunInitialMenu();
    if (console_viewer_.IsRegistrationDataReceived()) {
      // ProcessRegistrationData();
    }
  }
  console_viewer_.DisplayFarewellMessage();
}

void ConsolePresenter::ProcessRegistrationData() {
  std::string login = console_viewer_.LoginString();
  std::string password = console_viewer_.PasswordString();
}
