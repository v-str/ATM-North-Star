#include "mode_selector.h"

ModeSelector::ModeSelector() : app_(new Application) {}

void ModeSelector::RunProgramByMode(ProgramMode mode) {
  if (mode == kConsoleMode) {
    app_->RunProgram();
  }
}
