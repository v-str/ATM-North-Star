#ifndef MODE_SELECTOR
#define MODE_SELECTOR

#include <user_input.h>

class ModeSelector {
 public:
  enum UserSelections { kQuit, kConsoleMode, kGraphicalMode };

  void SuggestMode();
  int GetMode() const;

 private:
  int user_value_ = -1;
};

#endif  // MODE_SELECTOR
