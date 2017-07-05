#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QPoint>
#include <QRect>

class Geometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

  static QPoint VersionLabel();
  static QPoint CompanyNameLabel();
  static QPoint DateLabel();
  static QPoint TimeLabel();
  static QPoint TextLabel();
  static QRect SplashScreenFrame();

  static QRect SignInButton();
  static QRect RegistrationButton();
  static QRect DemoButton();

 private:
  static const int kInitialScreenWidth = 600;
  static const int kInitialScreenHeight = 400;

  static QPoint kVersionLabel;
  static QPoint kCompanyNameLabel;
  static QPoint kDateLabel;
  static QPoint kTimeLabel;
  static QPoint kTextLabel;
  static QRect kSplashScreenFrame;

  static QRect kSignInButton;
  static QRect kRegistrationButton;
  static QRect kDemoButton;
};

#endif  // GEOMETRY_H
