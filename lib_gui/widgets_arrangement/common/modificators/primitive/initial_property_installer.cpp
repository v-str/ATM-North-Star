#include <initial_property_installer.h>

#include <QWidget>

#include <widget_center_arranger.h>

void InitialPropertyInstaller::SetInitialProperties(
    QWidget* widget,
    int widget_width,
    int widget_height,
    const WidgetSize& widget_size) {
  switch (widget_size) {
    case kResize:
      widget->resize(widget_width, widget_height);
      break;
    case kFixedSize:
      widget->setFixedSize(widget_width, widget_height);
      break;
    default:
      break;
  }

  WidgetCenterArranger::MoveToCenter(widget);
}
