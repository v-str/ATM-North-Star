#include <mode_selector.h>

#include <messenger.h>
#include <user_input_processor.h>

void ModeSelector::SuggestMode() {
  user_value_ = -1;
  Messenger::ShowGreetingMessage();
  for (;;) {
    user_value_ = UserInputProcessor::GetMenuSection();
    if (user_value_ == kQuit || user_value_ == kConsoleMode ||
        user_value_ == kGraphicalMode) {
      break;
    }
    Messenger::IncorrectInput();
  }
}

int ModeSelector::GetMode() const { return user_value_; }
