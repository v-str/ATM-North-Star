#include <QApplication>

#include <mode_launcher.h>
#include <mode_selector.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector selector;
  selector.SuggestMode();

  ModeLauncher launcher;
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
}
