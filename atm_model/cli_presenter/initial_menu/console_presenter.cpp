#include <console_presenter.h>

#include <initial_messenger.h>

void ConsolePresenter::RunApplication() {
  InitialMessenger::DisplayInitialScreen();
  RunApplicationLoop();
}

int ConsolePresenter::UserChoice() const { return user_choice_; }

void ConsolePresenter::RunApplicationLoop() {
  for (;;) {
    user_choice_ = quit_handler_.GetDigitInputFromUser();

    if (user_choice_ == kDemo) {
      RunDemoMode();
      break;
    }
    if (user_choice_ == kRegistration) {
      RunRegistration();
      break;
    }
    if (user_choice_ == kLogin) {
      // temporary code
      // need make real login through database connection
      user_choice_ = -1;
      break;
    }
    if (user_choice_ == kQuit) {
      InitialMessenger::FarewellMessage();
      break;
    }

    InitialMessenger::ShowIncorrectMenuInput();
  }
}

void ConsolePresenter::RunDemoMode() {
  demo_mode_.RunDemoMenu();

  if (demo_mode_.UserWantToRegistrate()) {
    RunRegistration();
  }
}

void ConsolePresenter::RunRegistration() { registrator_.RunRegistrationMenu(); }
