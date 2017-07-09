#ifndef MAIN_WIDGET_GEOMETRY_H
#define MAIN_WIDGET_GEOMETRY_H

#include <QRect>

class MainWidgetGeometry {
 public:
  static QRect TimeLabel();
  static QRect MainFrame();

 private:
  static QRect kTimeLabel;
  static QRect kMainFrame;
};

#endif  // MAIN_WIDGET_GEOMETRY_H
