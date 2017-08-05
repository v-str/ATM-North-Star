#include <description_label.h>

#include <QResizeEvent>

#include <application_color.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <description_text.h>
#include <font_size_controller.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent), color_designer_(new AtmColorDesigner) {
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setGeometry(DescriptionMenuGeometry::DescriprionLabel());

  setWordWrap(true);
  font_size_controller_ =
      new FontSizeController(kInitialFontSize, kDivideFontSizeCoefficient);

  ColorizeWidget();
}

DescriptionLabel::~DescriptionLabel() {}

void DescriptionLabel::ShowAccountInfo() {
  setText(DescriptionText::AccountInfoText());
}

void DescriptionLabel::ShowCashRefillInfo() {
  setText(DescriptionText::CashRefillInfoText());
}

void DescriptionLabel::ShowCreditAppInfo() {
  setText(DescriptionText::CreditAppText());
}

void DescriptionLabel::ShowWithdrawalInfo() {
  setText(DescriptionText::WithdrawalInfoText());
}

void DescriptionLabel::ShowStatementInfo() {
  setText(DescriptionText::StatementIndoText());
}

void DescriptionLabel::resizeEvent(QResizeEvent* event) {
  font_size_controller_->ControlFontSize(event->size().width(), this);
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
