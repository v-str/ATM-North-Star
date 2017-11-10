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
      atm_checkbox_(new AtmCheckbox(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, this);
  SetConnections();

  atm_checkbox_->setGeometry(RegistrationMenuGeometry::FamiliarizedCheckbox());
  font_size_controller_.SetnitialMeasurements(description_label_, 0.7);
}

RegistrationDescription::~RegistrationDescription() {}

void RegistrationDescription::ChangeGeometry() {
  SetDeltaSize(CalculateDeltaSize(AtmComposer::GetDeltaSize(),
                                  AtmComposer::GetBackButtonDeltaSize()));

  AtmComposer::StretchWidget(RegistrationMenuGeometry::DescriptionFrame(),
                             Side::kRight | Side::kDown, 1.0, 0.97, this);

  AtmComposer::SetScalingProperties(Side::kDown, Side::kRight, false);
  AtmComposer::ScaleWidget(RegistrationMenuGeometry::FamiliarizedCheckbox(),
                           0.0, 0.85, 1.0, 0.0, atm_checkbox_);

  font_size_controller_.ControllFontSize(description_label_);
  atm_checkbox_->setFont(font_size_controller_.CurrentFont());

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
  atm_checkbox_->setCheckState(Qt::Unchecked);
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
  connect(atm_checkbox_, SIGNAL(stateChanged(int)), SLOT(CheckBoxClicked(int)));
}
