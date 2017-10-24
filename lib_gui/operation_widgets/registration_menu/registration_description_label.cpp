#include <registration_description_label.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <registration_menu_geometry.h>
#include <widget_font.h>

RegistrationDescriptionLabel::RegistrationDescriptionLabel(QWidget* parent)
    : QLabel(parent) {
  SetInitialSettings();
  SetText();
}

RegistrationDescriptionLabel::~RegistrationDescriptionLabel() {}

int RegistrationDescriptionLabel::GetInitialFontSize() const {
  return kInitialLabelFont;
}

void RegistrationDescriptionLabel::SetInitialSettings() {
  AtmColorDesigner::PaintSingleWidget(this);
  setFont(WidgetFont::SetFont(kInitialLabelFont));
  setGeometry(RegistrationMenuGeometry::DesctiptionLabel());
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setWordWrap(true);
}

void RegistrationDescriptionLabel::SetText() {
  setText(
      "Familiarize with registration rules:\n"
      "- Length of login: 6-35 latin symbols inclusively\n"
      "- Length of password: 6 symbols\n"
      "- Length of tooltip: no more than 50 symbols\n"
      "- Login must not contain special symbols\n"
      "( e.g. ; - % # ! and so on )\n"
      "- Password must not contain space symbols\n"
      "- Password may contain both latin alphabet symbols and arabic digits");
}
