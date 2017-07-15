#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QVector>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_frame_geometry.h>
#include <side.h>

#include <QDebug>

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new AtmButton("Sign-in", AtmButton::kRight, this)),
      registration_button_(
          new AtmButton("Registration", AtmButton::kRight, this)),
      demo_button_(new AtmButton("Demo", AtmButton::kRight, this)),
      atm_color_designer_(new AtmColorDesigner) {
  PaintWidgets();
  SetInitialSetting();
}

InitialMenu::~InitialMenu() { delete atm_color_designer_; }

void InitialMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void InitialMenu::PaintWidgets() {
  atm_color_designer_->PaintInitialFrame(this);
  atm_color_designer_->PaintWidgetSet(
      QList<QPushButton*>{sign_in_button_, registration_button_, demo_button_});
}

void InitialMenu::SetInitialSetting() {
  sign_in_button_->setGeometry(InitialFrameGeometry::SignInButton());
  registration_button_->setGeometry(InitialFrameGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialFrameGeometry::DemoButton());

  SetResizeProperties();
}

void InitialMenu::SetResizeProperties() {
  group_composer_.SetInitialGroupGeometry(
      QVector<QRect>{InitialFrameGeometry::SignInButton(),
                     InitialFrameGeometry::RegistrationButton(),
                     InitialFrameGeometry::DemoButton()});
  group_composer_.SetWidgetInterval(InitialFrameGeometry::WidgetInterval());

  group_composer_.SetShiftFactor(1.8, 0.25);
  group_composer_.SetShiftSide(Side::kRight | Side::kDown);

  group_composer_.SetStretchFactor(0.2, 0.2);
  group_composer_.SetStretchSide(Side::kDown | Side::kRight);

  group_composer_.SetTransformationType(GeometryComposer::kScale);

  group_composer_.KeepCenter(true);
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  group_composer_.SetDeltaSize(delta_size_);

  int x = geometry().x();
  int y = geometry().y();
  int width = geometry().width();
  int height = geometry().height();

  qDebug() << "x = " << x << "; y = " << y << "; w = " << width
           << "; h = " << height << "\n";

  group_composer_.ScaleVGroup(
      QVector<QWidget*>{sign_in_button_, registration_button_, demo_button_});

  int button_x = sign_in_button_->geometry().x();
  int button_y = sign_in_button_->geometry().y();
  int button_w = sign_in_button_->geometry().width();
  int button_h = sign_in_button_->geometry().height();

  qDebug() << "B(x) = " << button_x << "; B(y) = " << button_y
           << "; B(w) = " << button_w << "; B(h) = " << button_h << "\n";

  if (button_x > (width - button_w)) {
    QRect rect = QRect(width - button_w - 10, button_h, button_w, button_h);
    sign_in_button_->setGeometry(rect);
  }
}
