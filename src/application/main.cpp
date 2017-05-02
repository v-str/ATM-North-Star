#include <QApplication>

#include "app_manager.h"
#include "console_mode.h"
#include "main_form.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  AppManager app_manager;
  app_manager.SuggestMode();

  ConsoleMode console_mode;
  MainForm main_form;

  switch (app_manager.GetMode()) {
    case kConsoleMode:
      console_mode.RunInitialScreen();
      break;
    case kGuiMode:
      main_form.show();
      app.exec();
      break;
    default:
      break;
  }
}
