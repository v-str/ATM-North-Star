#ifndef SELECTOR_H
#define SELECTOR_H

#include <user_input_processor.h>

class Selector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();

  int GetMode() const;

 private:
  UserInputProcessor user_input_processor_;

  int user_input_ = -1;
};

#endif  // SELECTOR_H
