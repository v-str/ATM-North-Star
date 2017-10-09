#include <main_widget_composer.h>

#include <initial_frame_geometry.h>
#include <main_widget_geometry.h>
#include <side.h>

MainWidgetComposer::MainWidgetComposer() { SetDefaultComposing(); }

void MainWidgetComposer::SetMainFrame(QFrame* main_frame) {
  composer_.ComposeGeometry(MainWidgetGeometry::MainFrame(), main_frame);
}

void MainWidgetComposer::ComposeMenu(QWidget* widget) {
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), widget);
}

void MainWidgetComposer::SetDeltaSize(const DeltaSize& delta_size) {
  composer_.SetDeltaSize(delta_size);
}

void MainWidgetComposer::SetDefaultComposing() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
