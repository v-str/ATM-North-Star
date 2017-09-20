#include <launcher.h>
#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramInterface { kConsoleInterface, kGraphicalInterface };

  ModeConfigurator mode_configurator;
  Launcher launcher;

  int mode = mode_configurator.GetUIMode();

  if (mode == kConsoleInterface) {
    launcher.LaunchConsoleMode();
  } else if (mode == kGraphicalInterface) {
    launcher.LaunchGuiMode(argc, argv);
  } else {
    launcher.DisplayErrorReport();
  }
}
