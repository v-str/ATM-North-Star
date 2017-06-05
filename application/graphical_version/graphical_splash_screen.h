#ifndef GRAPHICAL_SPLASH_SCREEN_H
#define GRAPHICAL_SPLASH_SCREEN_H

class AtmSplashScreen;
class WidgetHider;

namespace gui {

class GraphicalSplashScreen {
 public:
  GraphicalSplashScreen();
  ~GraphicalSplashScreen();

  void RunInitialScreen();

 private:
  void SetSplashScreen();

  AtmSplashScreen* splash_screen_ = nullptr;
  WidgetHider* hider_ = nullptr;
};
}

#endif  // GRAPHICAL_SPLASH_SCREEN_H
