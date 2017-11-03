#include <registration_description.h>

#include <QCheckBox>
#include <QRect>
#include <QWidget>

#include <atm_composer.h>
#include <delta_size.h>
#include <registration_description_label.h>
#include <registration_menu_geometry.h>
#include <side.h>
#include <widget_font.h>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated),
      description_label_(new RegistrationDescriptionLabel(this)),
      familiarized_checkbox_(new QCheckBox("I'm familiarized", this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, this);
  SetCheckBox();
  SetConnections();
}

RegistrationDescription::~RegistrationDescription() {}

void RegistrationDescription::ChangeGeometry() {
  SetDeltaSize(CalculateDeltaSize(AtmComposer::GetDeltaSize(),
                                  AtmComposer::GetBackButtonDeltaSize()));

  AtmComposer::StretchWidget(RegistrationMenuGeometry::DescriptionFrame(),
                             Side::kRight | Side::kDown, 1.0, 0.97, this);
  AtmComposer::ScaleWidget(RegistrationMenuGeometry::FamiliarizedCheckbox(),
                           0.0, 0.97, 0.0, 0.0, familiarized_checkbox_);

  emit GeometryChanged();
}

void RegistrationDescription::SetCheckBox() {
  familiarized_checkbox_->setGeometry(
      RegistrationMenuGeometry::FamiliarizedCheckbox());
  familiarized_checkbox_->setFont(WidgetFont::SetFont(15));
}

DeltaSize RegistrationDescription::CalculateDeltaSize(
    const DeltaSize& app_delta_size, const DeltaSize& back_button_delta_size) {
  int height = app_delta_size.Height() - back_button_delta_size.Height();
  return DeltaSize(app_delta_size.Width(), height);
}

void RegistrationDescription::SetConnections() {
  connect(this, SIGNAL(GeometryChanged()), description_label_,
          SLOT(ChangeGeometry()));
}
