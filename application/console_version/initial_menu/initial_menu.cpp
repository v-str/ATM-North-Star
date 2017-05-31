#include <initial_menu.h>

#include <initial_messenger.h>

void InitialMenu::RunInitialMenu() {
  ShowInitialScreen();

  user_choice_ = quit_handler_.GetDigitInputFromUser();
}

int InitialMenu::UserChoice() const { return user_choice_; }

void InitialMenu::ShowInitialScreen() {
  InitialMessenger::DisplayInitialScreen();
}
