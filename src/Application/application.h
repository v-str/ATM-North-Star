#ifndef APPLICATION_H
#define APPLICATION_H

#include "initial_menu.h"
#include "initial_messenger.h"

class Application {
 public:
  void RunProgram();

 private:
  InitialMenu init_menu_;
  InitialMessenger init_screen_;
};

#endif  // APPLICATION_H
