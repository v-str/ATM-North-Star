#include <console_viewer.h>

#include <iostream>

#include <initial_messenger.h>
#include <menu_input_handler.h>

ConsoleViewer::ConsoleViewer() : input_handler_(new MenuInputHandler) {}

ConsoleViewer::~ConsoleViewer() { delete input_handler_; }

void ConsoleViewer::RunView() {
  DisplaySplashScreen();
  DisplayInitialMenu();
  RunSubMenu();
}

void ConsoleViewer::RunSubMenu() {
  for (;;) {
    user_input_ = input_handler_->GetDigitInputFromUser();

    if (IsInputAcceptable()) {
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

bool ConsoleViewer::IsInputAcceptable() {
  if (user_input_ == kLoginMenu) {
    return true;
  }
  if (user_input_ == kRegistrationMenu) {
    return true;
  }
  if (user_input_ == kDemoMenu) {
    return true;
  }
  if (user_input_ == kExit) {
    return true;
  }
  return false;
}
