#include <registration_description.h>

#include <QRect>
#include <QWidget>

#include <atm_button.h>
#include <registration_menu_geometry.h>
#include <side.h>

RegistrationDescription::RegistrationDescription(QWidget* parent)
    : BaseAtmFrame(parent, BackButtonCondition::kBackButtonDeactivated),
      next_button_(new AtmButton("Next", this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::DescriptionFrame());
  SetFrameAnimation(Side::kUp, Side::kDown, kHalfASecond, this);

  next_button_->setGeometry(RegistrationMenuGeometry::NextButton());
  color_designer_.PaintSingleWidget(next_button_);
}

RegistrationDescription::~RegistrationDescription() {}
