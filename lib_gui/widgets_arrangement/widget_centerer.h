#ifndef WIDGET_CENTERER_H
#define WIDGET_CENTERER_H

#include <QWidget>

class QRect;

class WidgetCenterer {
 public:
  static void MoveToCenter(QWidget* widget);
  static void MoveToCenterRelativelyOf(QWidget* move_widget,
                                       const QRect& position);
};

#endif  // WIDGET_CENTERER_H
