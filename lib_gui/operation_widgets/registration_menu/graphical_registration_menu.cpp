#include <graphical_registration_menu.h>

#include <QWidget>

#include <atm_button.h>
#include <atm_color_designer.h>
#include <atm_composer.h>
#include <registration_description.h>
#include <registration_menu_geometry.h>
#include <side.h>
#include <widget_font.h>

#include <QDebug>

GraphicalRegistrationMenu::GraphicalRegistrationMenu(QWidget* parent)
    : BaseAtmFrame(parent),
      registration_description_(new RegistrationDescription(this)),
      next_button_(new AtmButton("Next", this)) {
  SetInitialFrameGeometry(RegistrationMenuGeometry::RegistrationFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
  SetConnections();

  registration_description_->close();
  next_button_->SetFont(GetBackButton()->font());
  AtmColorDesigner::PaintSingleWidget(next_button_);
}

GraphicalRegistrationMenu::~GraphicalRegistrationMenu() {}

void GraphicalRegistrationMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());
  AtmComposer::ComposeBackButton(GetBackButton());
  CalculateNextButtonGeometry();
  AtmComposer::StretchWidget(RegistrationMenuGeometry::RegistrationFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);
  emit GeometryChanged();
}

void GraphicalRegistrationMenu::CalculateNextButtonGeometry() {
  int x = GetBackButton()->x() + GetBackButton()->width() + 5;
  int y = GetBackButton()->y();
  int width = GetBackButton()->width();
  int height = GetBackButton()->height();

  qDebug() << GetBackButton()->x() << " " << GetBackButton()->y() << " "
           << GetBackButton()->width() << " " << GetBackButton()->height()
           << "\n";

  qDebug() << x << " " << y << " " << width << " " << height;

  next_button_->setGeometry(x, y, width, height);
}

void GraphicalRegistrationMenu::SetConnections() {
  connect(this, SIGNAL(FrameOpened()), registration_description_, SLOT(Show()));
  connect(this, SIGNAL(FrameClosed()), registration_description_,
          SLOT(close()));
  connect(this, SIGNAL(GeometryChanged()), registration_description_,
          SLOT(ChangeGeometry()));
}
