#include <main_widget_composer.h>

#include <initial_frame_geometry.h>
#include <side.h>

MainWidgetComposer::MainWidgetComposer() { SetDefaultComposing(); }

void MainWidgetComposer::ComposeMenu(QWidget* widget) {
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), widget);
}

void MainWidgetComposer::SetDefaultComposing() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
