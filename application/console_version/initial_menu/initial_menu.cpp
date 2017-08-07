#include <initial_menu.h>

#include <initial_messenger.h>

void cli::InitialMenu::RunInitialMenu() { RunInitialMenuEventLoop(); }

int cli::InitialMenu::UserChoice() const { return user_choice_; }

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

void cli::InitialMenu::RunDemoMode() {
  demo_mode_.RunDemoMenu();

  if (demo_mode_.UserWantToRegistrate()) {
    RunRegistration();
  }
}

void cli::InitialMenu::RunRegistration() { registrator_.RunRegistrationMenu(); }
