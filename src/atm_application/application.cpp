#include "application.h"

void Application::RunProgram() {
  init_screen_.DisplayInitialScreen();

  init_menu_.RunProgram();
}
