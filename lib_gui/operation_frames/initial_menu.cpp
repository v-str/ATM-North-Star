#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_color_designer.h>

QRect InitialMenu::kSignInButtonGeometry = {220, 112, 140, 40};
QRect InitialMenu::kRegistrationButtonGeometry = {220, 162, 140, 40};
QRect InitialMenu::kDemoButtonGeometry = {220, 212, 140, 40};

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new QPushButton("Sign-in", this)),
      registration_button_(new QPushButton("Registration", this)),
      demo_button_(new QPushButton("Demo", this)),
      atm_color_designer_(new AtmColorDesigner) {
  PaintWidgets();
  SetInitialSetting();
}

InitialMenu::~InitialMenu() { delete atm_color_designer_; }

void InitialMenu::SetExtraGeometryParameters(int extra_width,
                                             int extra_height) {
  extra_width_ = extra_width;
  extra_height_ = extra_height;
}

void InitialMenu::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
}

void InitialMenu::SetInitialSetting() {
  sign_in_button_->setGeometry(kSignInButtonGeometry);
  registration_button_->setGeometry(kRegistrationButtonGeometry);
  demo_button_->setGeometry(kDemoButtonGeometry);
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  sign_in_button_->setGeometry(kSignInButtonGeometry.x() + extra_width_ / 2,
                               kSignInButtonGeometry.y() + extra_height_ / 2,
                               kSignInButtonGeometry.width(),
                               kSignInButtonGeometry.height());

  registration_button_->setGeometry(
      kRegistrationButtonGeometry.x() + extra_width_ / 2,
      kRegistrationButtonGeometry.y() + extra_height_ / 2,
      kRegistrationButtonGeometry.width(),
      kRegistrationButtonGeometry.height());

  demo_button_->setGeometry(kDemoButtonGeometry.x() + extra_width_ / 2,
                            kDemoButtonGeometry.y() + extra_height_ / 2,
                            kDemoButtonGeometry.width(),
                            kDemoButtonGeometry.height());
}
