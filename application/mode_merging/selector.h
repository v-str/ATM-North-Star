#ifndef SELECTOR_H
#define SELECTOR_H

#include <user_input_handler.h>

class Selector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();

  int GetMode() const;

 private:
  UserInputHandler user_input_processor_;

  int user_input_ = -1;
};

#endif  // SELECTOR_H
