#include <launcher.h>

#include <QApplication>

#include <gui_mode.h>
#include <initial_menu.h>

void Launcher::LaunchConsoleMode() {
  InitialMenu console_initial_menu;
  console_initial_menu.RunInitialMenu();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  GuiMode gui_mode;
  gui_mode.RunInitialScreen();
  application.exec();
}
