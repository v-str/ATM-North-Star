#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
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
  sign_in_button_->setGeometry(InitialFrameGeometry::SignInButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialFrameGeometry::DemoButton());
}

void InitialMenu::SetResizeGeometry() {
  composer_.SetShiftFactor(0.5, 0.5);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kShift);
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  composer_.SetDeltaSize(delta_size_);

  SetResizeGeometry();

  composer_.ComposeGeometry(InitialFrameGeometry::RegistrationButton(),
                            registration_button_);
  composer_.ComposeGeometry(InitialFrameGeometry::SignInButton(),
                            sign_in_button_);
  composer_.ComposeGeometry(InitialFrameGeometry::DemoButton(), demo_button_);
}
