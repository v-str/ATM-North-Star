#ifndef GUI_MODE_H
#define GUI_MODE_H

#include <memory>

#include <atm_splash_screen.h>

namespace gui {

class GuiMode {
 public:
  GuiMode();

  void RunInitialScreen();

 private:
  void SetSplashScreen();

  std::unique_ptr<AtmSplashScreen> splash_screen_;
};
}

#endif  // GUI_MODE_H
