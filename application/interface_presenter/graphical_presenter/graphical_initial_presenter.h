#ifndef GRAPHICAL_INITIAL_PRESENTER_H
#define GRAPHICAL_INITIAL_PRESENTER_H

class AtmSplashScreen;
class FrameAnimator;
class AtmMainWidget;

class GraphicalInitialPresenter {
 public:
  GraphicalInitialPresenter();
  ~GraphicalInitialPresenter();

  void RunApplication();

 private:
  void SetAnimation();
  void SetConnections();

  AtmSplashScreen* splash_screen_ = nullptr;
  FrameAnimator* frame_animator_ = nullptr;

  AtmMainWidget* main_widget_ = nullptr;
};

#endif  // GRAPHICAL_INITIAL_PRESENTER_H
