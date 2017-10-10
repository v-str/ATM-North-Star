#include <graphical_initial_presenter.h>

#include <QEasingCurve>
#include <QObject>
#include <QRect>

#include <atm_splash_screen.h>
#include <frame_animator.h>
#include <main_widget_presenter.h>
#include <side.h>

GraphicalInitialPresenter::GraphicalInitialPresenter()
    : splash_screen_(new AtmSplashScreen),
      frame_animator_(new FrameAnimator(splash_screen_)),
      main_widget_presenter_(new MainWidgetPresenter) {
  splash_screen_->SetCompanyName("North Star");

  SetAnimation();
  SetConnections();
}

GraphicalInitialPresenter::~GraphicalInitialPresenter() {
  delete splash_screen_;
  delete frame_animator_;
  delete main_widget_presenter_;
}

void GraphicalInitialPresenter::RunApplication() { splash_screen_->show(); }

void GraphicalInitialPresenter::SetAnimation() {
  frame_animator_->SetAnimationCurve(QEasingCurve::OutCirc);
  frame_animator_->SetAnimationDirection(Side::kUp);
}

void GraphicalInitialPresenter::SetConnections() {
  QObject::connect(splash_screen_, SIGNAL(PassPosition(QRect)), frame_animator_,
                   SLOT(Hide(QRect)));
  QObject::connect(splash_screen_, SIGNAL(PassPosition(const QRect&)),
                   main_widget_presenter_,
                   SLOT(SetWidgetGeometry(const QRect&)));
  QObject::connect(splash_screen_, SIGNAL(MaximizedScreen(bool)),
                   main_widget_presenter_, SLOT(SetMaximized(bool)));
  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()), splash_screen_,
                   SLOT(close()));
  QObject::connect(frame_animator_, SIGNAL(AnimationComplete()),
                   main_widget_presenter_, SLOT(ShowMainWidget()));
}
