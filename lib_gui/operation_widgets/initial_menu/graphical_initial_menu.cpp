#include <graphical_initial_menu.h>

#include <QList>
#include <QSizePolicy>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_composer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>
#include <widget_font.h>

GraphicalInitialMenu::GraphicalInitialMenu(QWidget* parent)
    : BaseAtmFrame(parent, BaseAtmFrame::kBackButtonDeactivated),
      button_frame_(new QFrame(this)),
      login_button_(new AtmButton("Login", button_frame_)),
      registration_button_(new AtmButton("Registration", button_frame_)),
      v_layout_(new QVBoxLayout) {
  SetInitialFrameGeometry(InitialFrameGeometry::InitialFrame());
  TuneButtons();
  SetButtonFrame();
  PaintWidgets();
  SetConnections();

  close();
}

GraphicalInitialMenu::~GraphicalInitialMenu() {}

void GraphicalInitialMenu::ChangeGeometry() {
  SetDeltaSize(AtmComposer::GetDeltaSize());

  AtmComposer::StretchWidget(InitialFrameGeometry::InitialFrame(),
                             Side::kRight | Side::kDown, 1.0, 1.0, this);
  AtmComposer::SetScalingProperties(Side::kRight | Side::kDown,
                                    Side::kRight | Side::kDown, true);
  AtmComposer::ScaleWidget(InitialFrameGeometry::ButtonFrame(), 0.5, 0.5, 0.5,
                           0.5, button_frame_);

  border_controller_.SetGeometryLimit(geometry());
  border_controller_.ControlWidget(button_frame_);
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

  button_frame_->setStyleSheet(
      "QFrame{"
      "border: 0px solid black;"
      "}");
}

void GraphicalInitialMenu::TuneButtons() {
  login_button_->setGeometry(InitialFrameGeometry::SignInButton());
  login_button_->SetFont(WidgetFont::SetFont(18));

  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  registration_button_->SetFont(WidgetFont::SetFont(18));
}

void GraphicalInitialMenu::SetButtonFrame() {
  button_frame_->setGeometry(InitialFrameGeometry::ButtonFrame());

  v_layout_->addWidget(login_button_);
  v_layout_->addWidget(registration_button_);

  button_frame_->setLayout(v_layout_);
}

void GraphicalInitialMenu::SetConnections() {
  connect(registration_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessRegistraionButtonClick()));
  connect(login_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessLoginButtonClick()));
}
