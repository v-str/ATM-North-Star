#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "console_editor.h"
#include "user_input.h"

class AppManager {
 public:
  void SuggestAppMode();

 private:
  void WriteWelcome();

  ConsoleEditor console_editor_;
  UserInput user_input_;
};

#endif  // APPMANAGER_H
