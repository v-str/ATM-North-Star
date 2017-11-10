#ifndef INITIAL_FRAME_GEOMETRY_H
#define INITIAL_FRAME_GEOMETRY_H

#include <QRect>

class InitialFrameGeometry {
 public:
  static QRect InitialFrame();
  static QRect ButtonFrame();
  static QRect LoginButton();
  static QRect RegistrationButton();
  static QRect DemoButton();

 private:
  static QRect kInitialFrame;
  static QRect kButtonFrame;
  static QRect kLoginButton;
  static QRect kRegistrationButton;
  static QRect kDemoButton;
};

#endif  // INITIAL_FRAME_GEOMETRY_H
