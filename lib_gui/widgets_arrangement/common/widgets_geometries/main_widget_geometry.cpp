#include <main_widget_geometry.h>

QRect MainWidgetGeometry::kTimeLabel = {485, 6, 100, 20};
QRect MainWidgetGeometry::kDateLabel = {370, 6, 110, 20};
QRect MainWidgetGeometry::kMainFrame = {5, 5, 590, 390};

QRect MainWidgetGeometry::TimeLabel() { return kTimeLabel; }

QRect MainWidgetGeometry::MainFrame() { return kMainFrame; }

QRect MainWidgetGeometry::DateLabel() { return kDateLabel; }
