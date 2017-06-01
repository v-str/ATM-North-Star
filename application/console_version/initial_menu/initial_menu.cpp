#include <initial_menu.h>

#include <initial_messenger.h>

void InitialMenu::RunInitialMenu() {
  ShowInitialScreen();

  RunInitialMenuEventLoop();
}

int InitialMenu::UserChoice() const { return user_choice_; }

void InitialMenu::ShowInitialScreen() {
  InitialMessenger::DisplayInitialScreen();
}

void InitialMenu::RunInitialMenuEventLoop() {
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
      // SayGoodbye();
      break;
    }

    InitialMessenger::ShowIncorrectMenuInput();
  }
}

void InitialMenu::RunDemoMode() {
  demo_mode_.RunDemoMode();

  if (demo_mode_.UserWantToRegistrate()) {
    RunRegistration();
  }
}

void InitialMenu::RunRegistration() { registrator_.RunRegistration(); }
