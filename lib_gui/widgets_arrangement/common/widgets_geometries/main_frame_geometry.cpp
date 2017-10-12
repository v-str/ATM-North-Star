#include <main_frame_geometry.h>

QRect MainFrameGeometry::kTimeLabel = {485, 6, 100, 20};
QRect MainFrameGeometry::kDateLabel = {370, 6, 110, 20};
QRect MainFrameGeometry::kMainFrame = {5, 5, 590, 390};

QRect MainFrameGeometry::TimeLabel() { return kTimeLabel; }

QRect MainFrameGeometry::MainFrame() { return kMainFrame; }

QRect MainFrameGeometry::DateLabel() { return kDateLabel; }
