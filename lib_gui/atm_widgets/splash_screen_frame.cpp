#include <splash_screen_frame.h>

#include <QLabel>
#include <QList>

#include <side.h>
#include <splash_screen_geometry.h>

SplashScreenFrame::SplashScreenFrame(QWidget *parent)
    : BaseAtmFrame(parent, kBackButtonDeactivated) {
  SetSplashScreenSettings();
  InitializeObjects();
  PaintWidgets();
}

SplashScreenFrame::~SplashScreenFrame() {}

void SplashScreenFrame::resizeEvent(QResizeEvent *event) {
  composer_.SetVersionLabel(version_label_);
}

void SplashScreenFrame::SetSplashScreenSettings() {
  SetInitialFrameGeometry(SplashScreenGeometry::SplashScreenFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, kHalfASecond, this);
}

void SplashScreenFrame::InitializeObjects() {
  version_label_ = new QLabel(this);
}

void SplashScreenFrame::PaintWidgets() {
  QList<QLabel *> label_list = {version_label_};

  color_designer_.PaintWidgetSet(&label_list);
}
