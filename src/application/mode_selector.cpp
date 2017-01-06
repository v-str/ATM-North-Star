#include "mode_selector.h"

void ModeSelector::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    console_app_->RunProgram();
  }
}
