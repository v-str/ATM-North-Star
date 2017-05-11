#include <mode_selector.h>

#include <initial_input.h>
#include <messenger.h>

void ModeSelector::SuggestMode() {
  user_choice_ = -1;
  Messenger::ShowGreetingMessage();
  for (;;) {
    user_choice_ = InitialInput::GetValueFromUser();
    if (user_choice_ == kExit || user_choice_ == kConsoleMode ||
        user_choice_ == kGraphicalMode) {
      break;
    }
    Messenger::IncorrectInput();
  }
}

int ModeSelector::GetMode() const { return user_choice_; }
