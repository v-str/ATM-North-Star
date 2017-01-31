#include "application.h"

void Application::RunProgram(int mode) {
  if (mode == kConsoleMode) {
    launcher_.RunInitialScreen();
  } else if (mode == kGraphicalMode) {
    // Temporary unavailable.
  }
}
