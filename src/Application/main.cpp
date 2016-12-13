#include "application.h"
#include "output_setup.h"

int main() {
  OutputSetup::SetupTwoStreamsForOutput();

  Application app;
  app.RunProgramByMode(Application::ProgramMode::kConsoleMode);
}
