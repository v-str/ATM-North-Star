#include <initial_menu_composer.h>

#include <QWidget>

#include <initial_frame_geometry.h>
#include <side.h>

InitialMenuComposer::InitialMenuComposer() {
  SetDefaultMenuComposingSettings();
  SetDefaultFrameComposingSettings();
}

void InitialMenuComposer::ComposeMenu(const DeltaSize& delta_size,
                                      QWidget* initial_menu) {
  menu_composer_.SetDeltaSize(delta_size);
  menu_composer_.ComposeGeometry(InitialFrameGeometry::InitialFrame(),
                                 initial_menu);
}

void InitialMenuComposer::ComposeFrame(const DeltaSize& delta_size,
                                       QWidget* frame) {
  frame_composer_.SetDeltaSize(delta_size);
  frame_composer_.ComposeGeometry(InitialFrameGeometry::ButtonFrame(), frame);
}

void InitialMenuComposer::SetDefaultMenuComposingSettings() {
  menu_composer_.SetStretchFactor(kXMenuFactor, kYMenuFactor);
  menu_composer_.SetStretchSide(Side::kRight | Side::kDown);
  menu_composer_.SetTransformationType(GeometryComposer::kStretch);
}

void InitialMenuComposer::SetDefaultFrameComposingSettings() {
  frame_composer_.SetShiftFactor(kXFrameFactor, kYFrameFactor);
  frame_composer_.SetShiftSide(Side::kRight | Side::kDown);
  frame_composer_.SetStretchFactor(kXFrameFactor, kYFrameFactor);
  frame_composer_.SetStretchSide(Side::kRight | Side::kDown);
  frame_composer_.SetTransformationType(GeometryComposer::kScale);
  frame_composer_.KeepCenter(true);
}
