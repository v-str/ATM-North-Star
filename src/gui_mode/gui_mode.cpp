#include <gui_mode.h>

#include <atm_splash_screen.h>

GuiMode::GuiMode() : splash_screen_(new AtmSplashScreen()) {
  ConfigureSplashScreen();
}

GuiMode::~GuiMode() { delete splash_screen_; }

void GuiMode::RunSplashScreen() { splash_screen_->show(); }

void GuiMode::ConfigureSplashScreen() {
  splash_screen_->SetCompanyName();
  splash_screen_->SetTextColor("red", "blue");
}
