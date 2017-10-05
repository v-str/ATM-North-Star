#include <main_widget_geometry.h>

QRect MainWidgetGeometry::kTimeLabel = {470, 5, 114, 20};
QRect MainWidgetGeometry::kDateLabel = {376, 5, 114, 20};
QRect MainWidgetGeometry::kMainFrame = {5, 5, 590, 390};

QRect MainWidgetGeometry::TimeLabel() { return kTimeLabel; }

QRect MainWidgetGeometry::MainFrame() { return kMainFrame; }

QRect MainWidgetGeometry::DateLabel() { return kDateLabel; }
