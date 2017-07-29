#include <graphical_splash_screen.h>

#include <QEasingCurve>
#include <QObject>
#include <QRect>

#include <atm_splash_screen.h>
#include <frame_animator.h>
#include <main_widget.h>
#include <side.h>

gui::GraphicalSplashScreen::GraphicalSplashScreen()
    : splash_screen_(new AtmSplashScreen),
      frame_animator_(new FrameAnimator(splash_screen_)),
      main_widget_(new gui::MainWidget) {
  splash_screen_->SetCompanyName("North Star");

  SetAnimation();
  SetConnections();
}

gui::GraphicalSplashScreen::~GraphicalSplashScreen() {
  delete splash_screen_;
  delete main_widget_;
}

void gui::GraphicalSplashScreen::RunInitialScreen() { splash_screen_->show(); }

void gui::GraphicalSplashScreen::SetAnimation() {
  frame_animator_->SetAnimationCurve(QEasingCurve::OutCirc);
  frame_animator_->SetAnimationDirection(Side::kUp);
}

void gui::GraphicalSplashScreen::SetConnections() {
  QObject::connect(splash_screen_, SIGNAL(PassPositionWhenEnterPressed(QRect)),
                   frame_animator_, SLOT(HideFrame(QRect)));

  QObject::connect(splash_screen_,
                   SIGNAL(PassPositionWhenEnterPressed(const QRect&)),
                   main_widget_, SLOT(SetWidgetGeometry(const QRect&)));

  QObject::connect(splash_screen_, SIGNAL(PassScreenSizeCondition(bool)),
                   main_widget_, SLOT(FullScreenSizeCondition(bool)));

  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()), splash_screen_,
                   SLOT(close()));

  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()), main_widget_,
                   SLOT(ShowMainWidget()));
}
