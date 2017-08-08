#include <launcher.h>
#include <mode_selector.h>

#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { Cli = 1, Gui };

  ModeConfigurator mode_configurator;
  Launcher app_launcher;

  switch (mode_configurator.GetMode()) {
    case Cli:
      app_launcher.LaunchConsoleMode();
      break;
    case Gui:
      app_launcher.LaunchGuiMode(argc, argv);
      break;
    default:
      break;
  }
}
