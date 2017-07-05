#include <initial_menu.h>

#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <application_color.h>
#include <atm_button.h>
#include <atm_color_designer.h>
#include <conversion_factor.h>
#include <initial_geometry.h>

QRect InitialMenu::kButton = {360, 62, 140, 40};

InitialMenu::InitialMenu(QWidget* parent)
    : QFrame(parent),
      sign_in_button_(new AtmButton("Sign-in", this)),
      registration_button_(new AtmButton("Registration", this)),
      demo_button_(new AtmButton("Demo", this)),
      button_(new AtmButton("&Test button", this)),
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
  atm_color_designer_->PaintWidgetSet(QList<QPushButton*>{
      sign_in_button_, registration_button_, demo_button_, button_});
}

void InitialMenu::SetInitialSetting() {
  sign_in_button_->setGeometry(InitialGeometry::SignInButton());
  registration_button_->setGeometry(InitialGeometry::RegistrationButton());
  demo_button_->setGeometry(InitialGeometry::DemoButton());

  button_->setGeometry(kButton);
}

void InitialMenu::resizeEvent(QResizeEvent*) {
  shifter_.SetDeltaSize(delta_size_);

  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5), QPoint(220, 112),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       sign_in_button_);
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5), QPoint(220, 162),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       registration_button_);
  shifter_.ShiftWidget(ConversionFactor(0.5, 0.5), QPoint(220, 212),
                       WidgetShifter::kShiftRight | WidgetShifter::kShiftDown,
                       demo_button_);
}
