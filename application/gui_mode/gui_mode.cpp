#include "gui_mode.h"

gui::GuiMode::GuiMode() : splash_screen_(new AtmSplashScreen) {}

void gui::GuiMode::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_->show();
}

void gui::GuiMode::SetSplashScreen() {
  splash_screen_->SetCompanyName("North Star");
  splash_screen_->SetSplashScreenAppearance("#CC6600", "rgb(252, 175, 62)",
                                            "rgb(252, 175, 62)");
  splash_screen_->SetAtmBlinkColor("#CC6600", "rgb(252, 175, 62)");
  splash_screen_->SetBackgroundColor();
}
