#include <launcher.h>

#include <QApplication>

#include <gui_mode.h>

Launcher::Launcher() : initial_menu_(new cli::InitialMenu) {}

void Launcher::LaunchConsoleMode() { initial_menu_->RunInitialMenu(); }

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  GuiMode gui_mode;
  gui_mode.RunInitialScreen();
  application.exec();
}
