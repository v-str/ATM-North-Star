#ifndef INITIAL_FRAME_GEOMETRY_H
#define INITIAL_FRAME_GEOMETRY_H

#include <QRect>

class InitialFrameGeometry {
 public:
  static QRect InitialFrame();
  static QRect SignInButton();
  static QRect RegistrationButton();
  static QRect DemoButton();

  static int WidgetInterval();

 private:
  static QRect kInitialFrame;
  static QRect kSignInButton;
  static QRect kRegistrationButton;
  static QRect kDemoButton;

  static const int widget_interval_pt_ = 10;
};

#endif  // INITIAL_FRAME_GEOMETRY_H
