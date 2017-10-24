#include <description_label.h>

#include <QResizeEvent>

#include <application_color.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <description_text.h>
#include <font_size_controller.h>
#include <text_animation.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent), text_animation_(new TextAnimation(this)) {
  SetDescriptionLabel();
  ColorizeWidget();
}

DescriptionLabel::~DescriptionLabel() { delete text_animation_; }

void DescriptionLabel::ShowAccountInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::AccountInfoText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::ShowCashRefillInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::CashRefillInfoText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::ShowCreditAppInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::CreditAppText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::ShowWithdrawalInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::WithdrawalInfoText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::ShowStatementInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::StatementIndoText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::resizeEvent(QResizeEvent* event) {
  FontSizeController size_controller;
  size_controller.ControlFontSize(11, 50, 6, event->size().width(), this);
}

void DescriptionLabel::SetDescriptionLabel() {
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setGeometry(DescriptionMenuGeometry::DescriprionLabel());
  setWordWrap(true);
}

void DescriptionLabel::ColorizeWidget() {
  QString stylesheet_string =
      "DescriptionLabel {"
      "color: %1;"
      "border: 1px solid %2"
      "}";

  setStyleSheet(stylesheet_string.arg(ApplicationColor::MainColor(),
                                      ApplicationColor::MainColor()));
}
