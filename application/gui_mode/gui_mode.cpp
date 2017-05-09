#include "gui_mode.h"

void GuiMode::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_.show();
}

void GuiMode::SetSplashScreen() {
  splash_screen_.SetCompanyName("North Star");
  splash_screen_.SetTextColor("#CC6600", "#808080");
  splash_screen_.SetAtmBlinkColor("#CC6600", "rgb(62, 74, 93)");
  splash_screen_.SetBackgroundColor("rgb(21, 24, 46);");
}
