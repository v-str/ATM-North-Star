#include <atm_main_widget.h>

#include <ui_atm_main_widget.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
}

AtmMainWidget::~AtmMainWidget() { delete ui; }
