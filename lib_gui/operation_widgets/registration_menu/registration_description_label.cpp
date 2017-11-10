#include <registration_description_label.h>

#include <QWidget>

#include <atm_color_designer.h>
#include <atm_composer.h>
#include <registration_menu_geometry.h>
#include <widget_font.h>

QString RegistrationDescriptionLabel::kDescriptionText =
    "Familiarize with registration rules:\n"
    "- Length of login: 6-35 latin symbols inclusively\n"
    "- Length of password: 6 symbols\n"
    "- Length of tooltip: no more than 50 symbols\n"
    "- Login must not contain special symbols\n"
    "( e.g. ; - % # ! and so on )\n"
    "- Password must not contain space symbols\n"
    "- Password may contain both latin alphabet symbols and arabic digits";

RegistrationDescriptionLabel::RegistrationDescriptionLabel(QWidget* parent)
    : QLabel(parent) {
  SetInitialSettings();
}

RegistrationDescriptionLabel::~RegistrationDescriptionLabel() {}

void RegistrationDescriptionLabel::ChangeGeometry() {
  AtmComposer::StretchWidget(RegistrationMenuGeometry::DesctiptionLabel(),
                             Side::kRight | Side::kDown, 1.0, 0.7, this);
}

void RegistrationDescriptionLabel::SetInitialSettings() {
  AtmColorDesigner::PaintSingleWidget(this);
  setText(kDescriptionText);
  setFont(WidgetFont::SetFont(15));
  setGeometry(RegistrationMenuGeometry::DesctiptionLabel());
  setAlignment(Qt::AlignLeft | Qt::AlignTop);
  setWordWrap(true);
}
