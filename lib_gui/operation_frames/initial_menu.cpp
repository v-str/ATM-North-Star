#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>

#include <QDebug>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new AtmButton("Sign-in", this)),
      registration_button_(new AtmButton("Registration", this)),
      demo_button_(new AtmButton("Demo", this)),
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

  SetResizeProperties();
}

void InitialMenu::SetResizeProperties() {
  group_composer_.SetInitialGroupGeometry(
      QVector<QRect>{InitialFrameGeometry::SignInButton(),
                     InitialFrameGeometry::RegistrationButton(),
                     InitialFrameGeometry::DemoButton()});
  group_composer_.SetWidgetInterval(InitialFrameGeometry::WidgetInterval());
  group_composer_.SetShiftFactor(3.8, 3.8);
  group_composer_.SetShiftSide(Side::kRight | Side::kDown);
  group_composer_.SetStretchFactor(3.8, 3.8);
  group_composer_.SetStretchSide(Side::kRight | Side::kDown);
  group_composer_.SetTransformationType(GeometryComposer::kScale);
  group_composer_.KeepCenter(true);
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  group_composer_.SetDeltaSize(delta_size_);
  border_controller_.SetGeometryLimit(geometry());

  group_composer_.ScaleVGroup(
      QVector<QWidget*>{sign_in_button_, registration_button_, demo_button_});

  border_controller_.ControlWidget(sign_in_button_);
}
