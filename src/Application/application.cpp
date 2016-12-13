#include "application.h"

void Application::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    main_menu_.RunProgram();
  }
}
