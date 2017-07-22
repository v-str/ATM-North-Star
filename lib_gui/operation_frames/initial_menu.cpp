#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QSizePolicy>
#include <QString>
#include <QVector>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>
#include <widget_hider.h>

#include <QDebug>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      button_frame_(new QFrame(this)),
      sign_in_button_(new AtmButton("Sign-in", button_frame_)),
      registration_button_(new AtmButton("Registration", button_frame_)),
      demo_button_(new AtmButton("Demo", button_frame_)),
      v_layout_(new QVBoxLayout),
      atm_color_designer_(new AtmColorDesigner),
      widget_hider_(new WidgetHider) {
  widget_hider_->SetWidgetForHideAnimation(this);
  widget_hider_->SetHideDirection(Side::kUp | Side::kLeft);

  SetButtonsInitialSetting();
  SetScalingProperties();
  SetButtonFrame();
  PaintWidgets();
  SetConnections();
}

InitialMenu::~InitialMenu() {
  delete atm_color_designer_;
  delete widget_hider_;
}

void InitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void InitialMenu::RememberGeometry() {
  emit PassWidgetGeometry(this->geometry());
}

void InitialMenu::Close() {
  emit AlreadyClosed();
  close();
}

void InitialMenu::PaintWidgets() {
  atm_color_designer_->PaintFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
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
  connect(demo_button_, SIGNAL(clicked(bool)), SLOT(RememberGeometry()));
  connect(this, SIGNAL(PassWidgetGeometry(QRect)), widget_hider_,
          SLOT(Hide(QRect)));
  connect(widget_hider_, SIGNAL(IsAlreadyHidden()), SLOT(Close()));
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  SetScalingProperties();
  composer_.SetDeltaSize(delta_size_);

  border_controller_.SetGeometryLimit(geometry());

  composer_.ComposeGeometry(InitialFrameGeometry::ButtonFrame(), button_frame_);

  border_controller_.ControlWidget(button_frame_);
}
