#ifndef APPLICATION_H
#define APPLICATION_H

#include "initial_menu.h"
#include "initial_screen.h"

class Application {
 public:
  void RunProgram();

 private:
  InitialMenu init_menu_;
  InitialScreen init_screen_;
};

#endif  // APPLICATION_H
