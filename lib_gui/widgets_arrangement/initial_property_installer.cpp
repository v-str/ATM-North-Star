#include <initial_property_installer.h>

#include <QWidget>

#include <widget_center_arranger.h>

void InitialPropertyInstaller::SetInitialProperties(QWidget* widget,
                                                    int widget_width,
                                                    int widget_height) {
  widget->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  widget->setFixedSize(widget_width, widget_height);
  WidgetCenterArranger::MoveToCenter(widget);
}
