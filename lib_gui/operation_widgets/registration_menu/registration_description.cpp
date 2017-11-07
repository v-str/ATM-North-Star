#include <registration_description.h>

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
      familiarized_checkbox_(new FamiliarizedCheckbox(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, this);
  SetConnections();
  font_controller_.TakeInitialMeasurements(description_label_);
}

RegistrationDescription::~RegistrationDescription() {}

void RegistrationDescription::ChangeGeometry() {
  SetDeltaSize(CalculateDeltaSize(AtmComposer::GetDeltaSize(),
                                  AtmComposer::GetBackButtonDeltaSize()));

  AtmComposer::StretchWidget(RegistrationMenuGeometry::DescriptionFrame(),
                             Side::kRight | Side::kDown, 1.0, 0.97, this);

  AtmComposer::SetScalingProperties(Side::kDown, Side::kRight, false);
  AtmComposer::ScaleWidget(RegistrationMenuGeometry::FamiliarizedCheckbox(),
                           0.0, 0.85, 1.0, 0.0, familiarized_checkbox_);

  font_controller_.ControllFontSize(description_label_);

  emit GeometryChanged();
}

void RegistrationDescription::CheckBoxClicked(int state) {
  if (state == Qt::Unchecked) {
    emit UserNotFamiliarized();
  }
  if (state == Qt::Checked) {
    emit UserFamiliarized();
  }
}

void RegistrationDescription::DeactivateFamiliarizing() {
  familiarized_checkbox_->setCheckState(Qt::Unchecked);
  emit UserNotFamiliarized();
}

DeltaSize RegistrationDescription::CalculateDeltaSize(
    const DeltaSize& app_delta_size, const DeltaSize& back_button_delta_size) {
  int height = app_delta_size.Height() - back_button_delta_size.Height();
  return DeltaSize(app_delta_size.Width(), height);
}

void RegistrationDescription::SetConnections() {
  connect(this, SIGNAL(GeometryChanged()), description_label_,
          SLOT(ChangeGeometry()));
  connect(familiarized_checkbox_, SIGNAL(stateChanged(int)),
          SLOT(CheckBoxClicked(int)));
}
