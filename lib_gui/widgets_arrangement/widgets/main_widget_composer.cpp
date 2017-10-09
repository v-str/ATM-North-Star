#include <main_widget_composer.h>

#include <side.h>

MainWidgetComposer::MainWidgetComposer() { SetDefaultComposing(); }

void MainWidgetComposer::ComposeMainFrame(QFrame* frame) {}

void MainWidgetComposer::SetDefaultComposing() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
