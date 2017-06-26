#include <initial_menu_frame.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_color_designer.h>

QRect InitialMenuFrame::kSignInButtonGeometry = {220, 112, 140, 40};
QRect InitialMenuFrame::kRegistrationButtonGeometry = {220, 162, 140, 40};
QRect InitialMenuFrame::kDemoButtonGeometry = {220, 212, 140, 40};

InitialMenuFrame::InitialMenuFrame(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new QPushButton("Sign-in", this)),
      registration_button_(new QPushButton("Registration", this)),
      demo_button_(new QPushButton("Demo", this)),
      atm_color_designer_(new AtmColorDesigner) {
  PaintWidgets();
  SetInitialSetting();
}

InitialMenuFrame::~InitialMenuFrame() { delete atm_color_designer_; }

void InitialMenuFrame::SetExtraGeometryParameters(int extra_width,
                                                  int extra_height) {
  extra_width_ = extra_width;
  extra_height_ = extra_height;
}

void InitialMenuFrame::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
}

void InitialMenuFrame::SetInitialSetting() {
  sign_in_button_->setGeometry(kSignInButtonGeometry);
  registration_button_->setGeometry(kRegistrationButtonGeometry);
  demo_button_->setGeometry(kDemoButtonGeometry);
}

void InitialMenuFrame::resizeEvent(QResizeEvent*) {
  sign_in_button_->setGeometry(
      kSignInButtonGeometry.x() + extra_width_ / 2, kSignInButtonGeometry.y(),
      kSignInButtonGeometry.width(), kSignInButtonGeometry.height());

  registration_button_->setGeometry(
      kRegistrationButtonGeometry.x() + extra_width_ / 2,
      kRegistrationButtonGeometry.y(), kRegistrationButtonGeometry.width(),
      kRegistrationButtonGeometry.height());

  demo_button_->setGeometry(
      kDemoButtonGeometry.x() + extra_width_ / 2, kDemoButtonGeometry.y(),
      kDemoButtonGeometry.width(), kDemoButtonGeometry.height());
}
