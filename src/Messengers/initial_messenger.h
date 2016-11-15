#ifndef INITIAL_MESSENGER_H
#define INITIAL_MESSENGER_H

#include "console_editor.h"

class InitialMessenger {
 public:
  void DisplayInitialScreen();

 private:
  void DisplayInitialMenu() const;
  void DisplayError() const;

  void DisplayLogotype();
  void EatLine();

  ConsoleEditor console_editor_;
};

#endif  // INITIAL_MESSENGER_H
