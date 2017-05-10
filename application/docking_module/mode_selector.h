#ifndef MODE_SELECTOR
#define MODE_SELECTOR

#include <user_input.h>

class ModeSelector {
 public:
  void SuggestMode();

  int GetMode();

 private:
  void WriteWelcome();

  UserInput user_input_;

  int choice_ = 0;
};

#endif  // MODE_SELECTOR
