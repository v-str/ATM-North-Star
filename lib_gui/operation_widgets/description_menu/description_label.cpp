#include <description_label.h>

#include <QResizeEvent>

#include <application_color.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <description_text.h>
#include <font_size_controller.h>
#include <text_animation.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent),
      color_designer_(new AtmColorDesigner),
      font_size_controller_(new FontSizeController(8, 50)),
      text_animation_(new TextAnimation(this)) {
  SetDescriptionLabel();
  ColorizeWidget();
}

DescriptionLabel::~DescriptionLabel() {
  delete font_size_controller_;
  delete color_designer_;
  delete text_animation_;
}

void DescriptionLabel::ShowAccountInfo() {
  text_animation_->SetTextForAnimation(DescriptionText::AccountInfoText());
  text_animation_->StartAnimation(kDelayMSec, this);
}

void DescriptionLabel::ShowCashRefillInfo() {}

void DescriptionLabel::ShowCreditAppInfo() {}

void DescriptionLabel::ShowWithdrawalInfo() {}

void DescriptionLabel::ShowStatementInfo() {}

void DescriptionLabel::resizeEvent(QResizeEvent* event) {
  font_size_controller_->ControlFontSize(event->size().width(), this);
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
