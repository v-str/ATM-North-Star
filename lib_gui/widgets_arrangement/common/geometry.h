#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QRect>

class Geometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

  static QRect VersionLabel();
  static QRect CompanyNameLabel();
  static QRect DateLabel();
  static QRect TimeLabel();
  static QRect TextLabel();
  static QRect SplashScreenFrame();

 private:
  static const int kStandardScreenWidth = 600;
  static const int kStandardScreenHeight = 400;

  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kDateLabel;
  static QRect kTimeLabel;
  static QRect kTextLabel;
  static QRect kSplashScreenFrame;
};

#endif  // GEOMETRY_H
