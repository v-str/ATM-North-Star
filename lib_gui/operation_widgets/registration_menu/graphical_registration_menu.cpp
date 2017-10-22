#include <graphical_registration_menu.h>

#include <QWidget>

#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      registration_description_(new RegistrationDescription(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
  SetConnections();

  registration_description_->close();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeGeometry(const DeltaSize& delta_size) {
  SetDeltaSize(delta_size);

  registration_composer_.ComposeRegistrationMenu(delta_size, this);

  //  operation_frame_delta_size_ =
  //      registration_composer_.ComposeDeltaSizeForDescription(
  //          GetBackButtonGeometry(), delta_size);
  // registration_description_->ChangeGeometry(operation_frame_delta_size_);
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), registration_description_, SLOT(Show()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(close()));
}
