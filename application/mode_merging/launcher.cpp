#include <launcher.h>

#include <QApplication>

#include <console_mode.h>
#include <gui_mode.h>

void Launcher::LaunchConsoleMode() {
  ConsoleMode console_mode;
  console_mode.RunATM();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  GuiMode gui_mode;
  gui_mode.RunInitialScreen();
  application.exec();
}
