#ifndef DEMO_MENU_GEOMETRY_H
#define DEMO_MENU_GEOMETRY_H

#include <QRect>

class DemoMenuGeometry {
 public:
  static QRect DemoFrame();
  static QRect BackButton();
  static QRect DescriprionFrame();

 private:
  static QRect kDemoFrame;
  static QRect kBackButton;

  static QRect kDescriptionFrame;
};

#endif  // DEMO_MENU_GEOMETRY_H
