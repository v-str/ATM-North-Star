#include "application.h"

void ModeSelector::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    console_app_.RunProgram();
  }
}
