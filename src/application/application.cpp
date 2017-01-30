#include "application.h"
#include "output_setup.h"

void Application::RunProgram(ProgramMode mode) {
  if (mode == kConsoleMode) {
    OutputSetup::SetupTwoStreamsForOutput();
  }

  launcher_.RunInitialScreen();
}
