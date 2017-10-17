#ifndef WIDGET_CENTER_ARRANGER_H
#define WIDGET_CENTER_ARRANGER_H

#include <QWidget>

class QRect;

class WidgetCenterArranger {
 public:
  enum MonitorCount { kOne = 1, kTwo, kThree, kMore };

  static void ArrangeWidget(QWidget* widget);

  static void MoveToCenter(QWidget* widget);
  static void MoveToCenterRelativelyOf(QWidget* move_widget,
                                       const QRect& position);

 private:
  static void DetermineAmountOfScreens();
  static void SetScreenDivider();

  static int kScreenCount;
  static int kScreenDivider;
};

#endif  // WIDGET_CENTER_ARRANGER_H
