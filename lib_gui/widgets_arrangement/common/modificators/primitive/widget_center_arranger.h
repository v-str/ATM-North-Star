#ifndef WIDGET_CENTER_ARRANGER_H
#define WIDGET_CENTER_ARRANGER_H

#include <QWidget>

class WidgetCenterArranger {
 public:
  enum MonitorCount { kOne = 1, kTwo, kThree, kMore };

  static void PlaceAtTheFirstMonitor(QWidget* widget);

  static void PlaceToCenterRelativelyOf(QWidget* move_widget,
                                        const QRect& rectangle);

 private:
  static int FirstScreenWidth();
  static int HalfOf(int length);
};

#endif  // WIDGET_CENTER_ARRANGER_H
