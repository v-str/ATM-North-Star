#include <widget_center_arranger.h>

#include <QApplication>
#include <QDesktopWidget>

void WidgetCenterArranger::ArrangeToCenter(QWidget* widget) {
  int x = HalfOf(QApplication::desktop()->width() /
                     QApplication::desktop()->screenCount() -
                 widget->width());

  int y = HalfOf(QApplication::desktop()->height() - widget->height());

  widget->move(x, y);
}

void WidgetCenterArranger::ArrangeToCenterRelativelyOf(QWidget* move_widget,
                                                       const QRect& rectangle) {
  int x = rectangle.x() + HalfOf(rectangle.width() - move_widget->width());
  int y = rectangle.y() + HalfOf(rectangle.height() - move_widget->height());

  move_widget->move(x, y);
}

int WidgetCenterArranger::HalfOf(int length) { return length / 2; }
