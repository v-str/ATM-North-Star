#include <launcher.h>
#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramInterface { kConsoleInterface, kGraphicalInterface };

  ModeConfigurator mode_configurator;
  Launcher app_launcher;

  int mode = mode_configurator.GetUIMode();

  if (mode == kConsoleInterface) {
    app_launcher.LaunchConsoleMode();
  } else if (mode == kGraphicalInterface) {
    app_launcher.LaunchGuiMode(argc, argv);
  } else {
    app_launcher.DisplayErrorReport();
  }
}
