#include <initial_menu.h>

#include <initial_messenger.h>

void cli::InitialMenu::RunInitialMenu() {
  ShowInitialScreen();

  RunInitialMenuEventLoop();
}

int cli::InitialMenu::UserChoice() const { return user_choice_; }

void cli::InitialMenu::ShowInitialScreen() {
  InitialMessenger::DisplayInitialScreen();
}

void cli::InitialMenu::RunInitialMenuEventLoop() {
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

void cli::InitialMenu::RunDemoMode() {
  demo_mode_.RunDemoMode();

  if (demo_mode_.UserWantToRegistrate()) {
    RunRegistration();
  }
}

void cli::InitialMenu::RunRegistration() { registrator_.RunRegistrationMenu(); }
