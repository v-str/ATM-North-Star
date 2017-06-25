#include <launcher.h>

#include <QApplication>

#include <application_color.h>
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
  SetGuiApplicationColor();
  gui::GraphicalSplashScreen splash_screen;
  splash_screen.RunInitialScreen();

  application.exec();
}

void Launcher::SetGuiApplicationColor() {
  ApplicationColor::SetMainColor("#00FFFF");
  ApplicationColor::SetSecondaryColor("#001933");
  ApplicationColor::SetAdditionalColor("#006666");
  ApplicationColor::SetSplashScreenBlinkColor("#00FFFF", "#009999");
  ApplicationColor::SetBackgroundColor("black");
}
