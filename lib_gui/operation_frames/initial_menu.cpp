#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_geometry.h>
#include <side.h>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new AtmButton("Sign-in", AtmButton::kRight, this)),
      registration_button_(
          new AtmButton("Registration", AtmButton::kRight, this)),
      demo_button_(new AtmButton("Demo", AtmButton::kRight, this)),
      atm_color_designer_(new AtmColorDesigner) {
  PaintWidgets();
  SetInitialSetting();
}

InitialMenu::~InitialMenu() { delete atm_color_designer_; }

void InitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void InitialMenu::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
}

void InitialMenu::SetInitialSetting() {
  sign_in_button_->setGeometry(InitialGeometry::SignInButton());
  registration_button_->setGeometry(InitialGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialGeometry::DemoButton());
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  transformer_.SetDeltaSize(delta_size_);

  transformer_.ShiftWidget(ConversionFactor(0.5, 0.5),
                           InitialGeometry::SignInButton(),
                           Side::kRight | Side::kDown, sign_in_button_);
  transformer_.ShiftWidget(ConversionFactor(0.5, 0.5),
                           InitialGeometry::RegistrationButton(),
                           Side::kRight | Side::kDown, registration_button_);
  transformer_.ShiftWidget(ConversionFactor(0.5, 0.5),
                           InitialGeometry::DemoButton(),
                           Side::kRight | Side::kDown, demo_button_);
}
