#include <demo_menu_geometry.h>

QRect DemoMenuGeometry::kDemoFrame = {5, 30, 580, 355};
QRect DemoMenuGeometry::kBackButton = {5, 320, 50, 30};
QRect DemoMenuGeometry::kDemoTransactionMenuFrame = {5, 70, 570, 245};

QRect DemoMenuGeometry::DemoFrame() { return kDemoFrame; }

QRect DemoMenuGeometry::BackButton() { return kBackButton; }

QRect DemoMenuGeometry::DemoTransactionMenuFrame() {
  return kDemoTransactionMenuFrame;
}
