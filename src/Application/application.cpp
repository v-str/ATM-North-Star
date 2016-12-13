#include "application.h"

void Application::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    init_screen_.DisplayInitialScreen();
    main_menu_.RunMenu();
  }
}
