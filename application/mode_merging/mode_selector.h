#ifndef MODE_SELECTOR_H
#define MODE_SELECTOR_H

#include <user_input_handler.h>

class ModeSelector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();

  int GetMode() const;

 private:
  UserInputHandler user_input_processor_;

  int user_input_ = -1;
};

#endif  // MODE_SELECTOR_H
