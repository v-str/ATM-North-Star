#ifndef DEMO_MENU_GEOMETRY_H
#define DEMO_MENU_GEOMETRY_H

#include <QRect>

class DemoMenuGeometry {
 public:
  static QRect DemoFrame();

 private:
  static QRect kDemoFrame;
};

#endif  // DEMO_MENU_GEOMETRY_H
