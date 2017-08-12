#ifndef GRAPHICAL_SPLASH_SCREEN_H
#define GRAPHICAL_SPLASH_SCREEN_H

class AtmSplashScreen;
class FrameAnimator;

namespace gui {

class MainWidget;

class GraphicalSplashScreen {
 public:
  GraphicalSplashScreen();
  ~GraphicalSplashScreen();

  void RunInitialScreen();

 private:
  void SetAnimation();
  void SetConnections();

  AtmSplashScreen* splash_screen_ = nullptr;
  FrameAnimator* frame_animator_ = nullptr;
  MainWidget* main_widget_ = nullptr;
};
}

#endif  // GRAPHICAL_SPLASH_SCREEN_H
