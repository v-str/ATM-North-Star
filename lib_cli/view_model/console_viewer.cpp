#include <console_viewer.h>

#include <iostream>

#include <initial_messenger.h>
#include <login_menu.h>
#include <menu_input_handler.h>

ConsoleViewer::ConsoleViewer()
    : input_handler_(new MenuInputHandler), login_menu_(new LoginMenu) {}

ConsoleViewer::~ConsoleViewer() {
  delete input_handler_;
  delete login_menu_;
  //  delete registration_menu_;
  //  delete demo_menu_;
}

void ConsoleViewer::RunView() {
  DisplaySplashScreen();
  DisplayInitialMenu();
  RunSubMenu();
}

void ConsoleViewer::RunLoginMenu() { login_menu_->RunLoginMenu(); }

void ConsoleViewer::RunRegistrationMenu() {}

void ConsoleViewer::RunDemoMenu() {}

void ConsoleViewer::DisplayFarewellMessage() {
  InitialMessenger::FarewellMessage();
}

int ConsoleViewer::GetSubMenu() const { return sub_menu_input_; }

void ConsoleViewer::RunSubMenu() {
  for (;;) {
    sub_menu_input_ = input_handler_->GetDigitInputFromUser();

    if (IsInputContainSubMenu()) {
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

bool ConsoleViewer::IsInputContainSubMenu() {
  if (sub_menu_input_ == kLoginMenu) {
    return true;
  }
  if (sub_menu_input_ == kRegistrationMenu) {
    return true;
  }
  if (sub_menu_input_ == kDemoMenu) {
    return true;
  }
  if (sub_menu_input_ == kExit) {
    return true;
  }
  return false;
}
