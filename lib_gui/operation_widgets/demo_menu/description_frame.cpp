#include <description_frame.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  SetGeometries();
  ColorizeWidgets();
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DescriptionFrame::SetGeometries() {
  setGeometry(DescriptionMenuGeometry::DescriprionFrame());
}

void DescriptionFrame::ColorizeWidgets() { color_designer_->PaintFrame(this); }
