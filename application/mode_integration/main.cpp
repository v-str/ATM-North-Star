#include <launcher.h>
#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { kConsoleMode, kGraphicalMode };

  ModeConfigurator mode_configurator;
  Launcher app_launcher;

  int mode = mode_configurator.GetMode();

  if (mode == kConsoleMode) {
    app_launcher.LaunchConsoleMode();
  } else if (mode == kGraphicalMode) {
    app_launcher.LaunchGuiMode(argc, argv);
  } else {
    app_launcher.DisplayErrorReport();
  }
}
