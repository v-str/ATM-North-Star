#include <registration_description_label.h>

#include <QWidget>

#include <registration_menu_geometry.h>
#include <widget_font.h>

RegistrationDescriptionLabel::RegistrationDescriptionLabel(QWidget* parent)
    : QLabel(parent) {
  SetInitialSettings();
  SetText();
}

RegistrationDescriptionLabel::~RegistrationDescriptionLabel() {}

void RegistrationDescriptionLabel::SetInitialSettings() {
  color_designer_.PaintSingleWidget(this);
  setFont(WidgetFont::SetFont(12));
  setGeometry(RegistrationMenuGeometry::DesctiptionLabel());
  setWordWrap(true);
}

void RegistrationDescriptionLabel::SetText() {
  setText(
      "This notice help you perform registration, please\n"
      "read it carefully:\n\n"
      "1. Length of login: 6-35 latin symbols inclusively\n"
      "2. Length of password: 6 symbols\n"
      "3. Length of tooltip: mo more than 50 symbols\n\n"
      "4. Login must not contain special symbols\n"
      "   ( e.g. ; - % # ! and so on )\n"
      "5. Password must not contain space symbols\n"
      "6. Password may contain both latin alphabet symbols\n"
      "   and arabic digits");
}
