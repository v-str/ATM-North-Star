#include <place_arranger.h>

#include <QApplication>
#include <QDesktopWidget>

void PlaceArranger::PlaceAtTheFirstMonitor(QWidget* widget) {
  int x = HalfOf(FirstScreenWidth() - widget->width());
  int y = HalfOf(QApplication::desktop()->height() - widget->height());

  widget->move(x, y);
}

void PlaceArranger::PlaceToCenterRelativelyOf(QWidget* move_widget,
                                              const QRect& rectangle) {
  int x = rectangle.x() + HalfOf(rectangle.width() - move_widget->width());
  int y = rectangle.y() + HalfOf(rectangle.height() - move_widget->height());

  move_widget->move(x, y);
}

int PlaceArranger::FirstScreenWidth() {
  return QApplication::desktop()->width() /
         QApplication::desktop()->screenCount();
}

int PlaceArranger::HalfOf(int length) { return length / 2; }
