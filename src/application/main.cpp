#include <QApplication>

#include "app_manager.h"
#include "atm_splash_screen.h"
#include "console_mode.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  AppManager app_manager;
  app_manager.SuggestMode();

  ConsoleMode console_mode;
  AtmSplashScreen splash_screen;

  switch (app_manager.GetMode()) {
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
