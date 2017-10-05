#include <base_atm_widget.h>

#include <QLabel>

#include <timedate_changer.h>

BaseAtmWidget::BaseAtmWidget(QWidget* parent) : QMainWindow(parent) {}

BaseAtmWidget::~BaseAtmWidget() {}

void BaseAtmWidget::ChangeTime(QLabel* time_label) {
  TimeDateChanger::ChangeTime(time_label);
}

void BaseAtmWidget::ChangeDate(QLabel* date_label) {
  TimeDateChanger::ChangeDate(date_label);
}
