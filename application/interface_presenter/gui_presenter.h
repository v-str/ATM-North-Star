#ifndef GUI_PRESENTER
#define GUI_PRESENTER

class AtmSplashScreen;
class FrameAnimator;

class MainWidget;

class GUIPresenter {
 public:
  GUIPresenter();
  ~GUIPresenter();

  void RunApplication();

 private:
  void SetAnimation();
  void SetConnections();

  AtmSplashScreen* splash_screen_ = nullptr;
  FrameAnimator* frame_animator_ = nullptr;
  MainWidget* main_widget_ = nullptr;
};

#endif  // GUI_PRESENTER
