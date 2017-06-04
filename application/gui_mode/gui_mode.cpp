#include <gui_mode.h>

#include <QObject>
#include <QRect>

gui::GuiMode::GuiMode() : splash_screen_(new AtmSplashScreen) {
  hider_.SetWidgetForHideAnimation(&splash_screen_);
  QObject::connect(&splash_screen_, SIGNAL(EnterIsPressed(const QRect&)),
                   &hider_, SLOT(Hide(const QRect&)));
  QObject::connect(&hider_, SIGNAL(IsAlreadyHidden()), &splash_screen_,
                   SLOT(CloseBeforeMainWidget()));
}

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
