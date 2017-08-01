#include <description_menu.h>

#include <QFrame>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <demo_menu_geometry.h>
#include <description_frame.h>
#include <side.h>

DescriptionMenu::DescriptionMenu(QWidget* parent)
    : BaseAtmFrame(parent), description_frame_(new DescriptionFrame(this)) {
  SetInitialFrameGeometry(DemoMenuGeometry::DemoFrame());
  SetInitialBackButtonGeometry(DemoMenuGeometry::BackButton());

  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);

  composer_.SetStretchFactor(1.0, 0.95);
  composer_.SetStretchSide(Side::kDown | Side::kRight);
  composer_.SetTransformationType(GeometryComposer::kStretch);
}

DescriptionMenu::~DescriptionMenu() {}

void DescriptionMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
}

void DescriptionMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);

  ScaleBackButton();

  composer_.SetDeltaSize(delta_size_);
  composer_.ComposeGeometry(DemoMenuGeometry::DescriprionFrame(),
                            description_frame_);
}
