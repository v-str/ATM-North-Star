#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include "console_editor.h"
#include "user_input.h"

class AppManager {
 public:
  void SuggestMode();

  int GetMode();

 private:
  void WriteWelcome();

  ConsoleEditor console_editor_;
  UserInput user_input_;

  int choice_ = 0;
};

#endif  // APP_MANAGER_H
