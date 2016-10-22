#include "application.h"
#include "initial_screen.h"

int main() {
  Application app;

  InitialScreen init_screen;

  init_screen.DisplayInitialScreen();
  app.RunProgram();
}
