#include <description_menu.h>

#include <QFrame>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <description_frame.h>
#include <description_label.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionMenu::DescriptionMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      description_label_(new DescriptionLabel(this)),
      description_frame_(new DescriptionFrame(this)) {
  SetInitialFrameGeometry(DescriptionMenuGeometry::DescriptionMenu());
  SetInitialBackButtonGeometry(DescriptionMenuGeometry::BackButton());

  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
}

DescriptionMenu::~DescriptionMenu() {}

void DescriptionMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void DescriptionMenu::resizeEvent(QResizeEvent*) {
  ScaleBackButton();
  BaseAtmFrame::SetDeltaSize(delta_size_);
  composer_.SetDeltaSize(delta_size_);

  ComposeDescriptionFrame();
  composer_.ComposeGeometry(DescriptionMenuGeometry::DescriprionFrame(),
                            description_frame_);

  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.SetShiftFactor(0.5, 0.0);
  composer_.SetShiftSide(Side::kDown | Side::kRight);
  composer_.SetStretchFactor(0.5, 1.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.ComposeGeometry(DescriptionMenuGeometry::DescriprionLabel(),
                            description_label_);
}

void DescriptionMenu::ComposeDescriptionFrame() {
  composer_.SetTransformationType(GeometryComposer::kStretch);
  composer_.SetStretchFactor(0.5, 1.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
}
