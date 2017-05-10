#include "gui_mode.h"

void GuiMode::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_.show();
}

void GuiMode::SetSplashScreen() {
  splash_screen_.SetCompanyName("North Star");
  splash_screen_.SetColor("#CC6600", "rgb(35, 53, 236)", "rgb(58, 140, 235)");
  splash_screen_.SetAtmBlinkColor("#CC6600", "rgb(252, 175, 62)");
  splash_screen_.SetBackgroundColor("rgb(21, 24, 46);");
}
