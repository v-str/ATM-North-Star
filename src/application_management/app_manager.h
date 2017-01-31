#ifndef APP_MANAGER_H
#define APP_MANAGER_H

#include "console_editor.h"
#include "user_input.h"

class AppManager {
 public:
  static void SuggestMode();

  static int GetMode();

 private:
  static void WriteWelcome();

  static ConsoleEditor console_editor_;
  static UserInput user_input_;

  static int choice_;
};

#endif  // APP_MANAGER_H
