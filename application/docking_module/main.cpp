#include <QApplication>

#include <console_mode.h>
#include <gui_mode.h>
#include <mode_selector.h>

#include <mode_launcher.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector selector;
  ModeLauncher launcher;

  selector.SuggestMode();

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
