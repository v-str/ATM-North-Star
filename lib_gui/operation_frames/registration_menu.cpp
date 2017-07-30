#include <registration_menu.h>

#include <QEasingCurve>
#include <QList>
#include <QResizeEvent>
#include <QWidget>

#include <atm_button.h>
#include <operation_frame.h>
#include <side.h>

RegistrationMenu::RegistrationMenu(QWidget* parent)
    : QFrame(parent),
      back_button_(new AtmButton("back", this)),
      operation_frame_(new OperationFrame(this)) {}

RegistrationMenu::~RegistrationMenu() {
  delete back_button_;
  delete operation_frame_;
}

void RegistrationMenu::SetDeltaSize(const DeltaSize& delta_size) {}
