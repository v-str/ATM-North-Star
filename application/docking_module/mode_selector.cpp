#include <mode_selector.h>

#include <initial_input.h>
#include <messenger.h>

void ModeSelector::SuggestMode() {
  user_value_ = -1;
  Messenger::ShowGreetingMessage();
  for (;;) {
    user_value_ = InitialInput::GetValueFromUser();
    if (user_value_ == kExit || user_value_ == kConsoleMode ||
        user_value_ == kGraphicalMode) {
      break;
    }
    Messenger::IncorrectInput();
  }
}

int ModeSelector::GetMode() const { return user_value_; }
