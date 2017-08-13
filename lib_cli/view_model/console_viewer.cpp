#include <console_viewer.h>

#include <iostream>

#include <initial_messenger.h>
#include <menu_input_handler.h>

ConsoleViewer::ConsoleViewer() : input_handler_(new MenuInputHandler) {}

ConsoleViewer::~ConsoleViewer() { delete input_handler_; }

void ConsoleViewer::RunInitialMenuLoop() {
  for (;;) {
    user_input_ = input_handler_->GetDigitInputFromUser();

    if (user_input_ == kLoginMenu) {
      // login_menu_->RunLoginMenu();
      std::cout << "\n\n"
                << "LOGIN MENU\n\n";
      break;
    } else if (user_input_ == kRegistrationMenu) {
      // registration_menu_->RunRegistrationMenu();
      std::cout << "\n\n"
                << "REGISTRATION MENU\n\n";
      break;
    } else if (user_input_ == kDemoMenu) {
      // demo_menu_->RunDemoMenu();
      std::cout << "\n\n"
                << "DEMO MENU\n\n";
      break;
    } else if (user_input_ == kExit) {
      InitialMessenger::FarewellMessage();
      break;
    } else {
      InitialMessenger::ShowIncorrectMenuInput();
    }
  }
}

void ConsoleViewer::DisplaySplashScreen() const {
  InitialMessenger::DisplaySplashScreen();
}

void ConsoleViewer::DisplayInitialMenu() const {
  InitialMessenger::DisplayInitialMenu();
}
