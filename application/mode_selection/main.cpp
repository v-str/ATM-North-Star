#include <QApplication>

#include "console_mode.h"
#include "main_form.h"
#include "mode_selector.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector mode_selector;
  mode_selector.SuggestMode();

  ConsoleMode console_mode;
  MainForm main_form;

  switch (mode_selector.GetMode()) {
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
