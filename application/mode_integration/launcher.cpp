#include <launcher.h>

#include <QApplication>

#include <graphical_splash_screen.h>
#include <splash_screen.h>  // add console prefix

Launcher::Launcher() : initial_menu_(new cli::InitialMenu) {}

void Launcher::LaunchConsoleMode() {
  cli::SplashScreen splash_screen;
  splash_screen.ShowSplashScreen();
  initial_menu_->RunInitialMenu();
}

void Launcher::LaunchGuiMode(int argc, char* argv[]) {
  QApplication application(argc, argv);
  Q_INIT_RESOURCE(atm_resources);
  gui::GraphicalSplashScreen splash_screen;
  splash_screen.RunInitialScreen();

  application.exec();
}
