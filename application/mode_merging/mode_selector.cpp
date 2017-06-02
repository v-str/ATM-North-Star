#include <mode_selector.h>

#include <iostream>

#include <messenger.h>

void ModeSelector::SuggestMode() {
  Messenger::ShowGreetingMessage();
  for (;;) {
    user_input_ = user_input_processor_.GetDigitInputFromUser();
    if (user_input_ == kQuit || user_input_ == kConsoleMode ||
        user_input_ == kGraphicalMode) {
      break;
    }
    Messenger::IncorrectInput();
  }
}

int ModeSelector::GetMode() const { return user_input_; }
