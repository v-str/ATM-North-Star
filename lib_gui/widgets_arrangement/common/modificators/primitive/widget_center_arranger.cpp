#include "widget_center_arranger.h"

#include <QApplication>
#include <QDesktopWidget>

int WidgetCenterArranger::kScreenCount = 1;
int WidgetCenterArranger::kScreenDivider = 1;

void WidgetCenterArranger::ArrangeWidget(QWidget* widget) {}

void WidgetCenterArranger::MoveToCenter(QWidget* widget) {
  DetermineAmountOfScreens();

  widget->move((QApplication::desktop()->width() / 4) - widget->width() / 2,
               (QApplication::desktop()->height() / 2) - widget->height() / 2);
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

void WidgetCenterArranger::SetScreenDivider() {}
