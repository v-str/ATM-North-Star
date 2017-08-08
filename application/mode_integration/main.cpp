#include <launcher.h>
#include <mode_selector.h>

#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { Error, Cli, Gui };

  ModeConfigurator mode_configurator;
  Launcher app_launcher;

  int mode = mode_configurator.GetMode();

  if (mode == Cli) {
    app_launcher.LaunchConsoleMode();
  }
  if (mode == Gui) {
    app_launcher.LaunchGuiMode(argc, argv);
  }
  if (mode == Error) {
    app_launcher.DisplayErrorReport();
  }
}
