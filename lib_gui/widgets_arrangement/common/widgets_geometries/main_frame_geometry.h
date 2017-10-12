#ifndef MAIN_FRAME_GEOMETRY_H
#define MAIN_FRAME_GEOMETRY_H

#include <QRect>

class MainFrameGeometry {
 public:
  static QRect TimeLabel();
  static QRect MainFrame();
  static QRect DateLabel();

 private:
  static QRect kTimeLabel;
  static QRect kDateLabel;
  static QRect kMainFrame;
};

#endif  // MAIN_FRAME_GEOMETRY_H
