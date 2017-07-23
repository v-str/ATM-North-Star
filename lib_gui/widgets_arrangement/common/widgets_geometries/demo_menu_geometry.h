#ifndef DEMO_MENU_GEOMETRY_H
#define DEMO_MENU_GEOMETRY_H

#include <QRect>

class DemoMenuGeometry {
 public:
  static QRect DemoFrame();
  static QRect BackButton();

 private:
  static QRect kDemoFrame;
  static QRect kBackButton;
};

#endif  // DEMO_MENU_GEOMETRY_H
