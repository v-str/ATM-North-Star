//#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"

#include <launcher.h>
#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  //  doctest::Context context;
  //  context.applyCommandLine(argc, argv);
  //  int tests_result = context.run();

  enum Mode { CLI, GUI };

  ModeConfigurator mode_configurator;
  int mode = mode_configurator.GetUIMode();

  Launcher launcher;
  if (mode == CLI) {
    launcher.LaunchConsoleMode();
  } else if (mode == GUI) {
    launcher.LaunchGuiMode(argc, argv);
  } else {
    launcher.DisplayErrorReport();
  }
}
