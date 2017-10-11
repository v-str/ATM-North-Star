#include <splash_screen_frame.h>

#include <QList>

#include <side.h>
#include <splash_screen_geometry.h>

SplashScreenFrame::SplashScreenFrame(QWidget *parent)
    : BaseAtmFrame(parent, kBackButtonDeactivated) {
  SetInitialSettings();
}

SplashScreenFrame::~SplashScreenFrame() {}

void SplashScreenFrame::SetInitialSettings() {
  SetInitialFrameGeometry(SplashScreenGeometry::SplashScreenFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, kHalfASecond, this);
}
