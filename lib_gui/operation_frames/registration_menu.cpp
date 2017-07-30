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
      operation_frame_(new OperationFrame(this)) {
  PaintWidgets();
}

RegistrationMenu::~RegistrationMenu() {
  delete back_button_;
  delete operation_frame_;
}

void RegistrationMenu::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void RegistrationMenu::PaintWidgets() {
  QList<QPushButton*> button_list{back_button_};
  operation_frame_->ColorizeButtons(button_list);
}
