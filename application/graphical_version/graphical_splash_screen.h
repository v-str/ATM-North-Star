#ifndef GRAPHICAL_SPLASH_SCREEN_H
#define GRAPHICAL_SPLASH_SCREEN_H

class AtmSplashScreen;
class WidgetHider;
class AtmMainWidget;

namespace gui {

class GraphicalSplashScreen {
 public:
  GraphicalSplashScreen();
  ~GraphicalSplashScreen();

  void RunInitialScreen();

 private:
  void SetSplashScreen();
  void SetConnections();

  AtmSplashScreen* splash_screen_ = nullptr;
  WidgetHider* hider_ = nullptr;
  AtmMainWidget* main_widget_ = nullptr;
};
}

#endif  // GRAPHICAL_SPLASH_SCREEN_H
