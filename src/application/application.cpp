#include "application.h"

void Application::RunProgram(int mode) {
  if (mode == kConsoleMode) {
    console_mode_.RunInitialScreen();
  } else if (mode == kGraphicalMode) {
    // gui
  }
}
