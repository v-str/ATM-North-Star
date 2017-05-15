#include <mode_launcher.h>

#include <QApplication>

#include <console_mode.h>
#include <gui_mode.h>

void ModeLauncher::LaunchConsoleMode() {
  ConsoleMode console_mode;
  console_mode.RunInitialScreen();
}

void ModeLauncher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  GuiMode gui_mode;
  gui_mode.RunInitialScreen();
  application.exec();
}
