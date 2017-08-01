#include <description_frame.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <demo_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  color_designer_->PaintFrame(this);

  setGeometry(DemoMenuGeometry::DescriprionFrame());

  color_designer_->PaintFrame(this);
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}
