#include <description_frame.h>

#include <QGridLayout>
#include <QList>
#include <QPushButton>
#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <side.h>

DescriptionFrame::DescriptionFrame(QWidget* parent)
    : QFrame(parent),
      color_designer_(new AtmColorDesigner),
      account_info_button_(new AtmButton("Account information", this)),
      cash_refill_button_(new AtmButton("Refill cash", this)),
      credit_app_button_(new AtmButton("Credit application", this)),
      cash_withdrawal_button_(new AtmButton("Cash withdrawal", this)),
      statement_butotn_(new AtmButton("Statement", this)),
      grid_layout_(new QGridLayout) {
  RemoveButtonsVisualOffset();
  SetGridLayout();
  SetGeometries();
  ColorizeWidgets();
}

DescriptionFrame::~DescriptionFrame() { delete color_designer_; }

void DescriptionFrame::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void DescriptionFrame::RemoveButtonsVisualOffset() {
  account_info_button_->SetOffsetSide(AtmButton::kNone);
  cash_refill_button_->SetOffsetSide(AtmButton::kNone);
  credit_app_button_->SetOffsetSide(AtmButton::kNone);
  cash_withdrawal_button_->SetOffsetSide(AtmButton::kNone);
  statement_butotn_->SetOffsetSide(AtmButton::kNone);
}

void DescriptionFrame::SetGridLayout() {
  grid_layout_->addWidget(account_info_button_, 0, 0, 2, 2);
  grid_layout_->addWidget(cash_refill_button_, 0, 2, 2, 2);
  grid_layout_->addWidget(credit_app_button_, 2, 0, 2, 2);
  grid_layout_->addWidget(cash_withdrawal_button_, 2, 2, 2, 2);
  grid_layout_->addWidget(statement_butotn_, 4, 1, 2, 2);

  setLayout(grid_layout_);
}

void DescriptionFrame::SetGeometries() {
  setGeometry(DescriptionMenuGeometry::DescriprionFrame());
}

void DescriptionFrame::ColorizeWidgets() {
  // color_designer_->PaintFrame(this);
  setStyleSheet(
      "DescriptionFrame {"
      "border: 0px;"
      "}");

  QList<QPushButton*> button_list{account_info_button_, cash_refill_button_,
                                  credit_app_button_, cash_withdrawal_button_,
                                  statement_butotn_};
  color_designer_->PaintWidgetSet(button_list);
}
