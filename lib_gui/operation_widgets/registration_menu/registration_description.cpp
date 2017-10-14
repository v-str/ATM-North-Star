#include <registration_description.h>

#include <QRect>
#include <QWidget>

#include <registration_menu_geometry.h>
#include <side.h>

#include <QDebug>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, kHalfASecond, this);
}

RegistrationDescription::~RegistrationDescription() {}
