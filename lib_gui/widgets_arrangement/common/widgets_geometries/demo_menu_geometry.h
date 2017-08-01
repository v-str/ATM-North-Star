#ifndef DEMO_MENU_GEOMETRY_H
#define DEMO_MENU_GEOMETRY_H

#include <QRect>

class DemoMenuGeometry {
 public:
  static QRect DemoFrame();
  static QRect BackButton();
  static QRect DemoTransactionMenuFrame();

 private:
  static QRect kDemoFrame;
  static QRect kBackButton;

  static QRect kDemoTransactionMenuFrame;
};

#endif  // DEMO_MENU_GEOMETRY_H
