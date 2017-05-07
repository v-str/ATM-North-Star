#ifndef GUI_MODE_H
#define GUI_MODE_H

#include <atm_splash_screen.h>

class GuiMode {
 public:
  void RunInitialScreen();

 private:
  void SetSplashScreen();

  AtmSplashScreen splash_screen_;
};

#endif  // GUI_MODE_H
