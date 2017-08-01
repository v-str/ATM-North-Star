#ifndef LOGIN_MENU_GEOMETRY_H
#define LOGIN_MENU_GEOMETRY_H

#include <QRect>

class LoginMenuGeometry {
 public:
  static QRect LoginFrame();
  static QRect BackButton();

 private:
  static QRect kLoginFrame;
  static QRect kBackButton;
};

#endif  // LOGIN_MENU_GEOMETRY_H
