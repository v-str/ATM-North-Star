#include <QApplication>

#include "console_mode.h"
#include "mode_selector.h"
#include "main_form.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector app_manager;
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
