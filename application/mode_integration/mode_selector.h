#ifndef MODE_SELECTOR_H
#define MODE_SELECTOR_H

#include <menu_input_handler.h>

class ModeSelector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();

  int GetMode() const;

 private:
  cli::MenuInputHandler input_handler_;

  int user_input_ = -1;
};

#endif  // MODE_SELECTOR_H
