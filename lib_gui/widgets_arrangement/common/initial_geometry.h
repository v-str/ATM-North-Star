#ifndef INITIAL_GEOMETRY_H
#define INITIAL_GEOMETRY_H

#include <QRect>

class InitialGeometry {
 public:
  static int InitialScreenWidth();
  static int InitialScreenHeight();

  static QRect VersionLabel();
  static QRect CompanyNameLabel();
  static QRect DateLabel();
  static QRect TimeLabel();
  static QRect TextLabel();
  static QRect SplashScreenFrame();

  static QRect SignInButton();
  static QRect RegistrationButton();
  static QRect DemoButton();

 private:
  static const int kInitialScreenWidth = 600;
  static const int kInitialScreenHeight = 400;

  static QRect kVersionLabel;
  static QRect kCompanyNameLabel;
  static QRect kDateLabel;
  static QRect kTimeLabel;
  static QRect kTextLabel;
  static QRect kSplashScreenFrame;

  static QRect kSignInButton;
  static QRect kRegistrationButton;
  static QRect kDemoButton;
};

#endif  // INITIAL_GEOMETRY_H
