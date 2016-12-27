#ifndef INITIAL_MESSENGER_H
#define INITIAL_MESSENGER_H

#include "output_configuration/console_editor.h"

class InitialMessenger {
 public:
  void DisplayInitialScreen();

 private:
  void DisplayInitialMenu() const;

  void DisplayLogotype();

  ConsoleEditor console_editor_;
};

#endif  // INITIAL_MESSENGER_H
