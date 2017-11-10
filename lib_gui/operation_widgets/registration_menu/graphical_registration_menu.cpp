#include <graphical_registration_menu.h>

#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <atm_composer.h>
#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>
#include <widget_font.h>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      registration_description_(new RegistrationDescription(this)),
      next_button_(new AtmButton("Next", this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
  SetConnections();
  SetNextButton();

  registration_description_->close();
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());
  AtmComposer::ComposeBackButton(BackButton());
  CalculateNextButtonGeometry();
  AtmComposer::StretchWidget(RegistrationMenuGeometry::RegistrationFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);

  BackButton()->SetFont(registration_description_->CurrentDescriptionFont());
  next_button_->SetFont(registration_description_->CurrentDescriptionFont());

  emit GeometryChanged();
}

void GraphicalRegistrationMenu::SetNextButton() {
  next_button_->SetFont(BackButton()->font());
  AtmColorDesigner::PaintSingleWidget(next_button_);
  next_button_->close();
}

void GraphicalRegistrationMenu::CalculateNextButtonGeometry() {
  int x = BackButton()->x() + BackButton()->width() + 10;
  next_button_->setGeometry(x, BackButton()->y(), BackButton()->width(),
                            BackButton()->height());
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), registration_description_, SLOT(Show()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(close()));
  connect(this, SIGNAL(GeometryChanged()), registration_description_,
          SLOT(ChangeGeometry()));
  connect(registration_description_, SIGNAL(UserFamiliarized()), next_button_,
          SLOT(show()));
  connect(registration_description_, SIGNAL(UserNotFamiliarized()),
          next_button_, SLOT(close()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(DeactivateFamiliarizing()));
  connect(next_button_, SIGNAL(clicked(bool)), registration_description_,
          SLOT(Close()));
}
