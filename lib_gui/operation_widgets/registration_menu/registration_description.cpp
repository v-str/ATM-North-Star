#include <registration_description.h>

#include <QRect>
#include <QWidget>

#include <atm_composer.h>
#include <registration_description_label.h>
#include <registration_menu_geometry.h>
#include <side.h>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated),
      description_label_(new RegistrationDescriptionLabel(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, this);
}

RegistrationDescription::~RegistrationDescription() {}

void RegistrationDescription::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());
  AtmComposer::StretchWidget(RegistrationMenuGeometry::DescriptionFrame(),
                             Side::kRight | Side::kDown, 1.0, 0.97, this);
}
