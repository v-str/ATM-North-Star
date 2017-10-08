#ifndef SPLASH_SCREEN_GEOMETRY_H
#define SPLASH_SCREEN_GEOMETRY_H

#include <QRect>

class SplashScreenGeometry {
 public:
  static QRect VersionLabel();
  static QRect CompanyNameLabel();
  static QRect DateLabel();
  static QRect TimeLabel();
  static QRect TextLabel();
  static QRect SplashScreenFrame();
  static QRect AtmLabel();

 private:
  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kDateLabel;
  static QRect kTimeLabel;
  static QRect kTextLabel;
  static QRect kSplashScreenFrame;
  static QRect kAtmLabel;
};

#endif  // SPLASH_SCREEN_GEOMETRY_H
