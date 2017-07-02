#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QPoint>
#include <QRect>

class Geometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

  static QPoint VersionLabel();
  static QRect CompanyNameLabel();
  static QRect DateLabel();
  static QRect TimeLabel();
  static QRect TextLabel();
  static QRect SplashScreenFrame();

 private:
  static const int kInitialScreenWidth = 600;
  static const int kInitialScreenHeight = 400;

  static QPoint kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kDateLabel;
  static QRect kTimeLabel;
  static QRect kTextLabel;
  static QRect kSplashScreenFrame;
};

#endif  // GEOMETRY_H
