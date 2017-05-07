#include <QApplication>

#include "atm_splash_screen.h"
#include "console_mode.h"
#include "mode_selector.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector mode_selector;
  mode_selector.SuggestMode();

  ConsoleMode console_mode;
  AtmSplashScreen splash_screen;

  switch (mode_selector.GetMode()) {
    case kConsoleMode:
      console_mode.RunInitialScreen();
      break;
    case kGuiMode:
      splash_screen.show();
      app.exec();
      break;
    default:
      break;
  }
}
