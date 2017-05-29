#include <selector.h>

#include <messenger.h>

void Selector::SuggestMode() {
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

int Selector::GetMode() const { return user_input_; }
