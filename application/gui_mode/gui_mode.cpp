#include "gui_mode.h"

gui::GuiMode::GuiMode() : splash_screen_(new AtmSplashScreen) {}

void gui::GuiMode::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_.show();
}

void gui::GuiMode::SetSplashScreen() {
  splash_screen_.SetCompanyName("North Star");
  splash_screen_.SetSplashScreenAppearance("#00FFFF", "#001933", "#009999");
  splash_screen_.SetAtmBlinkColor("#00FFFF", "#009999");
  splash_screen_.SetBackgroundColor();
}
