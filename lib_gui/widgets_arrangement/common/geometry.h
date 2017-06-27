#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QRect>

class Geometry {
 public:
  static QRect VersionLabel();
  static QRect CompanyNameLabel();
  static QRect DateLabel();
  static QRect TimeLabel();
  static QRect TextLabel();
  static QRect SplashScreenFrame();

 private:
  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kDateLabel;
  static QRect kTimeLabel;
  static QRect kTextLabel;
  static QRect kSplashScreenFrame;
};

#endif  // GEOMETRY_H
