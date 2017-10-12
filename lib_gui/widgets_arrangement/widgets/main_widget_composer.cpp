#include <main_widget_composer.h>

#include <initial_frame_geometry.h>
#include <main_frame_geometry.h>
#include <side.h>
#include <splash_screen_geometry.h>

MainWidgetComposer::MainWidgetComposer() { SetDefaultComposing(); }

void MainWidgetComposer::ComposeMainFrame(QWidget *main_frame) {
  composer_.ComposeGeometry(MainFrameGeometry::MainFrame(), main_frame);
}

void MainWidgetComposer::ComposeInitialMenu(QWidget *initial_menu) {
  composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(), initial_menu);
}

void MainWidgetComposer::ComposeSplashScreen(QWidget *splash_screen) {
  composer_.ComposeGeometry(SplashScreenGeometry::SplashScreenFrame(),
                            splash_screen);
}

void MainWidgetComposer::SetDeltaSize(const DeltaSize &delta_size) {
  composer_.SetDeltaSize(delta_size);
}

void MainWidgetComposer::SetDefaultComposing() {
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
