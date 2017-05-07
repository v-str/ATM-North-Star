#include "widget_centerer.h"

#include <QApplication>
#include <QDesktopWidget>

void WidgetCenterer::MoveToCenter(QWidget* widget) {
  widget->move((QApplication::desktop()->width() / 4) - widget->width() / 2,
               (QApplication::desktop()->height() / 2) - widget->height() / 2);
}
