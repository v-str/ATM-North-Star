#include <cli_presenter.h>

#include <initial_messenger.h>

CLIPresenter::CLIPresenter() {
  console_viewer_ = std::unique_ptr<ConsoleViewer>(new ConsoleViewer);
}

void CLIPresenter::RunApplication() {
  console_viewer_->DisplaySplashScreen();
  InitialMessenger::DisplayInitialMenu();
  RunApplicationLoop();
}

int CLIPresenter::UserChoice() const { return user_choice_; }

void CLIPresenter::RunApplicationLoop() {
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

void CLIPresenter::RunDemoMode() {
  demo_mode_.RunDemoMenu();

  if (demo_mode_.UserWantToRegistrate()) {
    RunRegistration();
  }
}

void CLIPresenter::RunRegistration() { registrator_.RunRegistrationMenu(); }
