#include <graphical_initial_menu.h>

#include <QList>
#include <QSizePolicy>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_composer.h>
#include <conversion_factor.h>
#include <font_size_generator.h>
#include <initial_frame_geometry.h>
#include <side.h>
#include <widget_font.h>

GraphicalInitialMenu::GraphicalInitialMenu(QWidget* parent)
    : BaseAtmFrame(parent, BaseAtmFrame::kBackButtonDeactivated),
      login_button_(new AtmButton("Login", this)),
      registration_button_(new AtmButton("Registration", this)) {
  SetInitialFrameGeometry(InitialFrameGeometry::InitialFrame());
  TuneButtons();
  SetButtons();

  font_size_generator_ = new FontSizeGenerator(1.3, *login_button_);

  PaintWidgets();
  SetConnections();
  close();
}

GraphicalInitialMenu::~GraphicalInitialMenu() { delete font_size_generator_; }

void GraphicalInitialMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());

  AtmComposer::StretchWidget(InitialFrameGeometry::InitialFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);
  AtmComposer::SetScalingProperties(Side::kRight | Side::kDown,
                                    Side::kRight | Side::kDown, true);
  AtmComposer::ScaleWidget(InitialFrameGeometry::LoginButton(), 0.5, 0.5, 0.5,
                           0.2, login_button_);

  registration_button_->setGeometry(
      login_button_->x(), login_button_->y() + login_button_->height() + 10,
      login_button_->width(), login_button_->height());

  font_size_generator_->GenerateFontSize(login_button_);
  font_size_generator_->GenerateFontSize(registration_button_);
}

void GraphicalInitialMenu::ProcessDemoButtonClick() {
  emit PassGeometryForHide(geometry());
  emit DemoButtonClicked();
}

void GraphicalInitialMenu::ProcessRegistraionButtonClick() {
  emit PassGeometryForHide(geometry());
  emit RegistrationButtonClicked();
}

void GraphicalInitialMenu::ProcessLoginButtonClick() {
  emit PassGeometryForHide(geometry());
  emit LoginButtonClicked();
}

void GraphicalInitialMenu::ShowMenu() {
  SetFrameAnimation(Side::kLeft, Side::kRight, this);
  Show();
}

void GraphicalInitialMenu::ShowFirstTime() {
  SetFrameAnimation(Side::kLeft, Side::kDown, this);
  Show();
}

void GraphicalInitialMenu::PaintWidgets() {
  QList<QPushButton*> button_list{login_button_, registration_button_};
  ColorizeButtons(&button_list);
}

void GraphicalInitialMenu::TuneButtons() {
  login_button_->setGeometry(InitialFrameGeometry::LoginButton());
  login_button_->SetFont(WidgetFont::SetFont(18));

  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  registration_button_->SetFont(WidgetFont::SetFont(18));
}

void GraphicalInitialMenu::SetButtons() {
  login_button_->setGeometry(InitialFrameGeometry::LoginButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
}

void GraphicalInitialMenu::SetConnections() {
  connect(registration_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessRegistraionButtonClick()));
  connect(login_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessLoginButtonClick()));
}
