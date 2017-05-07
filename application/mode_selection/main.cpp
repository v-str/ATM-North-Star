#include <QApplication>

#include <console_mode.h>
#include <gui_mode.h>
#include <mode_selector.h>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);
  Q_INIT_RESOURCE(atm_resources);

  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector mode_selector;
  mode_selector.SuggestMode();

  ConsoleMode console_mode;
  GuiMode gui_mode;

  switch (mode_selector.GetMode()) {
    case kConsoleMode:
      console_mode.RunInitialScreen();
      break;
    case kGuiMode:
      gui_mode.RunInitialScreen();
      app.exec();
      break;
    default:
      break;
  }
}
