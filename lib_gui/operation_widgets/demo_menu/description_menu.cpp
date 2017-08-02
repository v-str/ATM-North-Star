#include <description_menu.h>

#include <QFrame>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <description_frame.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionMenu::DescriptionMenu(QWidget* parent)
    : BaseAtmFrame(parent), description_frame_(new DescriptionFrame(this)) {
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
}

void DescriptionMenu::ComposeDescriptionFrame() {
  composer_.SetStretchFactor(1.0, 1.0);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}
