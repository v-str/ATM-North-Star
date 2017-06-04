#ifndef GUI_MODE_H
#define GUI_MODE_H

#include <atm_splash_screen.h>

namespace gui {

class GuiMode {
 public:
  GuiMode();

  void RunInitialScreen();

 private:
  void SetSplashScreen();

  AtmSplashScreen splash_screen_;
};
}

#endif  // GUI_MODE_H
