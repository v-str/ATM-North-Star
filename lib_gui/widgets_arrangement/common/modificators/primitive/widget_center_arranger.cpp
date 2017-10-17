#include "widget_center_arranger.h"

#include <QApplication>
#include <QDesktopWidget>

#include <QDebug>

int WidgetCenterArranger::kScreenCount = 1;

void WidgetCenterArranger::ArrangeWidget(QWidget* widget) {
  DetermineAmountOfScreens();

  int x = (QApplication::desktop()->width() / kScreenCount) / 2 -
          widget->width() / 2;
  int y = (QApplication::desktop()->height() / 2) - widget->height() / 2;

  widget->move(x, y);
}

void WidgetCenterArranger::MoveToCenterRelativelyOf(QWidget* move_widget,
                                                    const QRect& position) {
  int x = position.x() + (position.width() / 2) - (move_widget->width() / 2);
  int y = position.y() + (position.height() / 2) - (move_widget->height() / 2);

  move_widget->move(x, y);
}

void WidgetCenterArranger::DetermineAmountOfScreens() {
  kScreenCount = QApplication::desktop()->screenCount();
}
