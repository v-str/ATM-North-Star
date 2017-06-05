#ifndef GRAPHICAL_SPLASH_SCREEN_H
#define GRAPHICAL_SPLASH_SCREEN_H

class AtmSplashScreen;
class WidgetHider;

namespace gui {

class MainWidget;

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
  MainWidget* main_widget_ = nullptr;
};
}

#endif  // GRAPHICAL_SPLASH_SCREEN_H
