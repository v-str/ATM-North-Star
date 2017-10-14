#include <graphical_registration_menu.h>

#include <QWidget>

#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent), description_(new RegistrationDescription(this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetBackButton(RegistrationMenuGeometry::BackButton());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);
  SetConnections();

  description_->close();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeRegistrationMenuGeometry(
    const DeltaSize& delta_size) {
  ComposeWidgets(delta_size);
  BaseAtmFrame::SetDeltaSize(delta_size);
  ScaleBackButton();

  description_->SetDeltaSize(delta_size);
}

void GraphicalRegistrationMenu::ComposeWidgets(const DeltaSize& delta_size) {
  registration_composer_.ComposeGeometry(
      delta_size, RegistrationMenuGeometry::RegistrationFrame(), this);
  registration_composer_.ComposeGeometry(
      delta_size, RegistrationMenuGeometry::DescriptionFrame(), description_);
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), description_, SLOT(Show()));
}
