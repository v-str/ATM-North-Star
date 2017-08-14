#include <graphical_initial_menu.h>

#include <QList>
#include <QSizePolicy>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>

GraphicalInitialMenu::GraphicalInitialMenu(QWidget* parent)
    : BaseAtmFrame(parent, BaseAtmFrame::kBackButtonDeactivated),
      button_frame_(new QFrame(this)),
      login_button_(new AtmButton("Login", button_frame_)),
      registration_button_(new AtmButton("Registration", button_frame_)),
      description_button_(new AtmButton("Description", button_frame_)),
      v_layout_(new QVBoxLayout) {
  SetInitialFrameGeometry(InitialFrameGeometry::InitialFrame());
  SetFrameAnimation(Side::kLeft, Side::kRight, kHalfASecond, this);

  SetButtonGeometry();
  SetButtonFrame();
  SetButtonFrameScalingProperties();
  PaintWidgets();
  SetConnections();
}

GraphicalInitialMenu::~GraphicalInitialMenu() {}

void GraphicalInitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  BaseAtmFrame::SetDeltaSize(delta_size);
  delta_size_ = delta_size;
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

void GraphicalInitialMenu::PaintWidgets() {
  QList<QPushButton*> button_list{login_button_, registration_button_,
                                  description_button_};

  ColorizeButtons(button_list);
}

void GraphicalInitialMenu::SetButtonGeometry() {
  login_button_->setGeometry(InitialFrameGeometry::SignInButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  description_button_->setGeometry(InitialFrameGeometry::DemoButton());
}

void GraphicalInitialMenu::SetButtonFrameScalingProperties() {
  composer_.SetShiftFactor(kXFactor, kYFactor);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(kXFactor, kYFactor);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.KeepCenter(true);
}

void GraphicalInitialMenu::SetButtonFrame() {
  button_frame_->setGeometry(InitialFrameGeometry::ButtonFrame());

  button_frame_->setStyleSheet(
      "QFrame {"
      "border: 0px;}");

  v_layout_->addWidget(login_button_);
  v_layout_->addWidget(registration_button_);
  v_layout_->addWidget(description_button_);

  button_frame_->setLayout(v_layout_);
}

void GraphicalInitialMenu::SetConnections() {
  connect(description_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessDemoButtonClick()));
  connect(registration_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessRegistraionButtonClick()));
  connect(login_button_, SIGNAL(clicked(bool)),
          SLOT(ProcessLoginButtonClick()));
}

void GraphicalInitialMenu::resizeEvent(QResizeEvent*) {
  BaseAtmFrame::SetDeltaSize(delta_size_);
  SetButtonFrameScalingProperties();

  composer_.SetDeltaSize(delta_size_);
  composer_.ComposeGeometry(InitialFrameGeometry::ButtonFrame(), button_frame_);

  border_controller_.SetGeometryLimit(geometry());
  border_controller_.ControlWidget(button_frame_);
}
