#include <gui_mode.h>

#include <atm_splash_screen.h>

GuiMode::GuiMode() : splash_screen_(new AtmSplashScreen()) {
  ConfigureSplashScreen();
}

GuiMode::~GuiMode() { delete splash_screen_; }

void GuiMode::RunSplashScreen() { splash_screen_->show(); }

void GuiMode::ConfigureSplashScreen() {
  splash_screen_->SetCompanyName("North star");
  splash_screen_->SetTextColor("rgb(206, 92, 0)", "rgb(136, 138, 133)");
  splash_screen_->SetAtmBlinkColor("rgb(206, 92, 0)", "rgb(252, 175, 62)");
  splash_screen_->SetBackgroundImage();
}
