#include <description_label.h>

#include <application_color.h>
#include <atm_color_designer.h>
#include <description_menu_geometry.h>
#include <description_text.h>

DescriptionLabel::DescriptionLabel(QWidget* parent)
    : QLabel(parent), color_designer_(new AtmColorDesigner) {
  setGeometry(DescriptionMenuGeometry::DescriprionLabel());
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

void DescriptionLabel::ColorizeWidget() {
  QString stylesheet_string =
      "DescriptionLabel {"
      "color: %1;"
      "border: 1px solid %2"
      "}";

  setStyleSheet(stylesheet_string.arg(ApplicationColor::MainColor(),
                                      ApplicationColor::MainColor()));
}
