#ifndef MODE_SELECTOR
#define MODE_SELECTOR

#include <user_input_processor.h>

class ModeSelector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();
  int GetMode() const;

 private:
  UserInputProcessor user_input_processor_;

  int user_input_ = -1;
};

#endif  // MODE_SELECTOR
