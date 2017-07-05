#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <geometry.h>

QRect InitialMenu::kButton = {220, 62, 140, 40};

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new AtmButton("Sign-in", this)),
      registration_button_(new AtmButton("Registration", this)),
      demo_button_(new AtmButton("Demo", this)),
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
  sign_in_button_->setGeometry(Geometry::SignInButton());
  registration_button_->setGeometry(Geometry::RegistrationButton());
  demo_button_->setGeometry(Geometry::DemoButton());
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  shifter_.SetDeltaSize(delta_size_);

  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       QPoint(220, 112), sign_in_button_);
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       QPoint(220, 162), registration_button_);
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       QPoint(220, 212), demo_button_);
}
