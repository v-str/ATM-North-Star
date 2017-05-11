#ifndef MODE_SELECTOR
#define MODE_SELECTOR

#include <user_input.h>

class ModeSelector {
 public:
  void SuggestMode();
  int GetMode() const;

 private:
  int user_choice_ = -1;
};

#endif  // MODE_SELECTOR
