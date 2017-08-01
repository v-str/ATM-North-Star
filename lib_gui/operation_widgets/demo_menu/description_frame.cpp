#include <description_frame.h>

#include <atm_color_designer.h>
#include <demo_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  color_designer_->PaintFrame(this);
  setGeometry(DemoMenuGeometry::DescriprionFrame());
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DescriptionFrame::resizeEvent(QResizeEvent*) {
  composer_.SetDeltaSize(delta_size_);
  composer_.ComposeGeometry(DemoMenuGeometry::DescriprionFrame(), this);
}

void DescriptionFrame::SetFrameScaling() {
  composer_.SetShiftFactor(1.0, 1.0);
  composer_.SetShiftSide(Side::kDown | Side::kRight);
}
