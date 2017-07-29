#include <initial_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QPushButton>
#include <QSizePolicy>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <operation_frame.h>
#include <side.h>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      button_frame_(new QFrame(this)),
      sign_in_button_(new AtmButton("Sign-in", button_frame_)),
      registration_button_(new AtmButton("Registration", button_frame_)),
      demo_button_(new AtmButton("Demo", button_frame_)),
      v_layout_(new QVBoxLayout),
      operation_frame_(new OperationFrame(this)) {
  setGeometry(InitialFrameGeometry::InitialFrame());

  operation_frame_->SetOperationFrame(this);

  SetFrameAnimation();
  SetButtonsInitialSetting();
  SetScalingProperties();
  SetButtonFrame();
  PaintWidgets();
  SetConnections();
}

InitialMenu::~InitialMenu() {}

void InitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void InitialMenu::ProcessDemoButtonClick() {
  emit PassGeometryForHide(geometry());
  emit DemoButtonClicked();
}

void InitialMenu::Show() {
  QRect widget_geometry = {
      InitialFrameGeometry::InitialFrame().x(),
      InitialFrameGeometry::InitialFrame().y(),
      InitialFrameGeometry::InitialFrame().width() + delta_size_.Width(),
      InitialFrameGeometry::InitialFrame().height() + delta_size_.Height()};

  setGeometry(widget_geometry);
  emit PassGeometryForExtrude(widget_geometry);
}

void InitialMenu::PaintWidgets() {
  QList<QPushButton*> button_list{sign_in_button_, registration_button_,
                                  demo_button_};

  operation_frame_->ColorizeButtons(button_list);
}

void InitialMenu::SetFrameAnimation() {
  operation_frame_->SetAnimationDirection(Side::kUp, Side::kDown);
}

void InitialMenu::SetButtonsInitialSetting() {
  SetButtonGeometry();
  SetButtonSizePolicy();
}

void InitialMenu::SetButtonGeometry() {
  sign_in_button_->setGeometry(InitialFrameGeometry::SignInButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialFrameGeometry::DemoButton());
  button_frame_->setGeometry(InitialFrameGeometry::ButtonFrame());
}

void InitialMenu::SetButtonSizePolicy() {
  QSizePolicy size_policy = sign_in_button_->sizePolicy();
  size_policy.setVerticalPolicy(QSizePolicy::Expanding);

  sign_in_button_->setSizePolicy(size_policy);
  registration_button_->setSizePolicy(size_policy);
  demo_button_->setSizePolicy(size_policy);
}

void InitialMenu::SetScalingProperties() {
  composer_.SetShiftFactor(kHalfOfSize, kHalfOfHeight);
  composer_.SetShiftSide(Side::kRight | Side::kDown);
  composer_.SetStretchFactor(kHalfOfSize, kHalfOfHeight);
  composer_.SetStretchSide(Side::kRight | Side::kDown);
  composer_.SetTransformationType(GeometryComposer::kScale);
  composer_.KeepCenter(true);
}

void InitialMenu::SetButtonFrame() {
  button_frame_->setStyleSheet(
      "QFrame {"
      "border: 0px;}");

  v_layout_->addWidget(sign_in_button_);
  v_layout_->addWidget(registration_button_);
  v_layout_->addWidget(demo_button_);

  button_frame_->setLayout(v_layout_);
}

void InitialMenu::SetConnections() {
  connect(demo_button_, SIGNAL(clicked(bool)), SLOT(ProcessDemoButtonClick()));

  connect(this, SIGNAL(PassGeometryForExtrude(QRect)), operation_frame_,
          SLOT(StartExtrudingFrame(QRect)));

  connect(operation_frame_, SIGNAL(ExtrudingComplete()), SLOT(show()));

  connect(this, SIGNAL(PassGeometryForHide(QRect)), operation_frame_,
          SLOT(StartHidingFrame(QRect)));

  connect(operation_frame_, SIGNAL(HidingComplete()), SLOT(close()));
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  SetScalingProperties();

  composer_.SetDeltaSize(delta_size_);

  border_controller_.SetGeometryLimit(geometry());

  composer_.ComposeGeometry(InitialFrameGeometry::ButtonFrame(), button_frame_);

  border_controller_.ControlWidget(button_frame_);
}
