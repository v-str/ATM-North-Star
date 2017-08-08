#include <launcher.h>
#include <mode_selector.h>

#include <mode_configurator.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector selector;
  selector.SuggestMode();

  Launcher launcher;
  switch (selector.GetMode()) {
    case kConsoleMode:
      launcher.LaunchConsoleMode();
      break;
    case kGuiMode:
      launcher.LaunchGuiMode(argc, argv);
      break;
    default:
      break;
  }

  //  ModeConfigurator mode_configurator;
  // Launcher application_launcher;
  // application_launcher.RunApp(mode_configurator.GetMode());
}
