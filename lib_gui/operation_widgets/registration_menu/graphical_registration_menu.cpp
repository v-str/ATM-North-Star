#include <graphical_registration_menu.h>

#include <QWidget>

#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      registration_description_(new RegistrationDescription(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetBackButton(RegistrationMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
  SetConnections();

  registration_description_->close();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeRegistrationMenuGeometry(
    const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  ScaleBackButton();

  delta_size_ = delta_size;
  operation_frame_delta_size_ =
      registration_composer_.ComposeDeltaSizeForDescription(
          GetBackButtonGeometry(), delta_size);

  ComposeWidgets();
}

void GraphicalRegistrationMenu::ComposeWidgets() {
  registration_composer_.ComposeGeometry(
      delta_size_, RegistrationMenuGeometry::RegistrationFrame(), this);
  registration_composer_.ComposeGeometry(
      operation_frame_delta_size_, RegistrationMenuGeometry::DescriptionFrame(),
      registration_description_);
  registration_description_->SetDeltaSize(operation_frame_delta_size_);
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), registration_description_, SLOT(Show()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(close()));
}
