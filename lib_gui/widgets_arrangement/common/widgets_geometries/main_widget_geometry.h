#ifndef MAIN_WIDGET_GEOMETRY_H
#define MAIN_WIDGET_GEOMETRY_H

#include <QRect>

class MainWidgetGeometry {
 public:
  static QRect TimeLabel();
  static QRect MainFrame();
  static QRect DateLabel();

 private:
  static QRect kTimeLabel;
  static QRect kDateLabel;
  static QRect kMainFrame;
};

#endif  // MAIN_WIDGET_GEOMETRY_H
