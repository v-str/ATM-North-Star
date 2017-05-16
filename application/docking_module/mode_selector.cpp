#include <mode_selector.h>

#include <menu_input_processor.h>
#include <messenger.h>

void ModeSelector::SuggestMode() {
  user_value_ = -1;
  Messenger::ShowGreetingMessage();
  for (;;) {
    user_value_ = MenuInputProcessor::GetMenuItem();
    if (user_value_ == kQuit || user_value_ == kConsoleMode ||
        user_value_ == kGraphicalMode) {
      break;
    }
    Messenger::IncorrectInput();
  }
}

int ModeSelector::GetMode() const { return user_value_; }
