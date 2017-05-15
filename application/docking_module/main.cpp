#include <QApplication>

#include <console_mode.h>
#include <gui_mode.h>
#include <mode_selector.h>

int main(int argc, char* argv[]) {
  enum ProgramMode { kConsoleMode = 1, kGuiMode };

  ModeSelector mode_selector;
  mode_selector.SuggestMode();

  switch (mode_selector.GetMode()) {
    case kConsoleMode: {
      ConsoleMode console_mode;
      console_mode.RunInitialScreen();
      break;
    }
    case kGuiMode: {
      QApplication app(argc, argv);
      Q_INIT_RESOURCE(atm_resources);
      GuiMode gui_mode;
      gui_mode.RunInitialScreen();
      app.exec();
      break;
    }
    default:
      break;
  }
}
