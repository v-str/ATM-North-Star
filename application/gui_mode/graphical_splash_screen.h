#ifndef GRAPHICAL_SPLASH_SCREEN_H
#define GRAPHICAL_SPLASH_SCREEN_H

#include <atm_splash_screen.h>
#include <widget_hider.h>

namespace gui {

class GraphicalSplashScreen {
 public:
  GraphicalSplashScreen();

  void RunInitialScreen();

 private:
  void SetSplashScreen();

  AtmSplashScreen splash_screen_;
  WidgetHider hider_;
};
}

#endif  // GRAPHICAL_SPLASH_SCREEN_H
