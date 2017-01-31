#include "application.h"
#include "output_setup.h"

void Application::RunProgram(int mode) {
  if (mode == kConsoleMode) {
    OutputSetup::SetupTwoStreamsForOutput();
  }

  launcher_.RunInitialScreen();
}
