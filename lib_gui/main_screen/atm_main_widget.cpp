#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include <initial_property_installer.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
}

AtmMainWidget::~AtmMainWidget() { delete ui; }
