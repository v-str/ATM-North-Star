#include "application.h"

void Application::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    console_app_.RunProgram();
  }
}
