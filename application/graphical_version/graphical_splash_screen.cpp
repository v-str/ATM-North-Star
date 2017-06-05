#include <graphical_splash_screen.h>

#include <QObject>
#include <QRect>

#include <atm_splash_screen.h>
#include <widget_hider.h>

gui::GraphicalSplashScreen::GraphicalSplashScreen()
    : splash_screen_(new AtmSplashScreen), hider_(new WidgetHider) {
  hider_->SetWidgetForHideAnimation(splash_screen_);
  QObject::connect(splash_screen_, SIGNAL(EnterIsPressed(const QRect&)), hider_,
                   SLOT(Hide(const QRect&)));
  QObject::connect(hider_, SIGNAL(IsAlreadyHidden()), splash_screen_,
                   SLOT(close()));
}

gui::GraphicalSplashScreen::~GraphicalSplashScreen() {
  delete splash_screen_;
  delete hider_;
}

void gui::GraphicalSplashScreen::RunInitialScreen() {
  SetSplashScreen();
  splash_screen_->show();
}

void gui::GraphicalSplashScreen::SetSplashScreen() {
  splash_screen_->SetCompanyName("North Star");
  splash_screen_->SetSplashScreenAppearance("#00FFFF", "#001933", "#009999");
  splash_screen_->SetAtmBlinkColor("#00FFFF", "#009999");
  splash_screen_->SetBackgroundColor();
}
