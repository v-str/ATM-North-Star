#include <demo_menu_geometry.h>

QRect DemoMenuGeometry::kDemoFrame = {5, 30, 580, 355};
QRect DemoMenuGeometry::kBackButton = {5, 320, 40, 25};

QRect DemoMenuGeometry::DemoFrame() { return kDemoFrame; }

QRect DemoMenuGeometry::BackButton() { return kBackButton; }
