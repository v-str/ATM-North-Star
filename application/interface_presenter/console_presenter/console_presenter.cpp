#include <console_presenter.h>

#include <string>

void ConsolePresenter::RunApplication() {
  initial_menu_.RunSplashScreen();
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

  // registration_handler_.HandleRegistrationData(login, password);
  // if (registration_handler_.IsRegistrationOk()) {
  // registrate
  // } else {
  // console_viewer_.DisplayRegistrationError(ErrorType);
  // }
}
