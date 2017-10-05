#include <gui_presenter.h>

#include <QEasingCurve>
#include <QObject>
#include <QRect>

#include <atm_splash_screen.h>
#include <frame_animator.h>
#include <main_widget.h>
#include <side.h>

GUIPresenter::GUIPresenter()
    : splash_screen_(new AtmSplashScreen),
      frame_animator_(new FrameAnimator(splash_screen_)),
      main_widget_(new MainWidget) {
  splash_screen_->SetCompanyName("North Star");

  SetAnimation();
  SetConnections();
}

GUIPresenter::~GUIPresenter() {
  delete splash_screen_;
  delete frame_animator_;
  delete main_widget_;
}

void GUIPresenter::RunApplication() { splash_screen_->show(); }

void GUIPresenter::SetAnimation() {
  frame_animator_->SetAnimationCurve(QEasingCurve::OutCirc);
  frame_animator_->SetAnimationDirection(Side::kUp);
}

void GUIPresenter::SetConnections() {
  QObject::connect(splash_screen_, SIGNAL(PassPositionWhenEnterPressed(QRect)),
                   frame_animator_, SLOT(HideFrame(QRect)));

  QObject::connect(splash_screen_,
                   SIGNAL(PassPositionWhenEnterPressed(const QRect&)),
                   main_widget_, SLOT(SetWidgetGeometry(const QRect&)));

  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()), splash_screen_,
                   SLOT(close()));

  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()), main_widget_,
                   SLOT(ShowMainWidget()));
}
