#include <description_frame.h>

#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent), color_designer_(new AtmColorDesigner) {
  PerformInitialization();
  SetGeometries();
  ColorizeWidgets();
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DescriptionFrame::PerformInitialization() {
  account_info_button_ = new AtmButton("Account Info", this);
  refill_button_ = new AtmButton("Refill", this);
  credit_app_button_ = new AtmButton("Credit app", this);
  withdrawal_button_ = new AtmButton("Widthdrawal", this);
  statement_butotn_ = new AtmButton("Statement", this);
}

void DescriptionFrame::SetGeometries() {
  setGeometry(DescriptionMenuGeometry::DescriprionFrame());
}

void DescriptionFrame::ColorizeWidgets() { color_designer_->PaintFrame(this); }
