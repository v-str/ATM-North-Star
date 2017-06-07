#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include <initial_property_installer.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
}

AtmMainWidget::~AtmMainWidget() { delete ui; }

void AtmMainWidget::resizeEvent(QResizeEvent*) {
  int extra_width = width() - minimumWidth();
  int extra_height = height() - minimumHeight();
  ui->main_fraim->setGeometry(5, 5, 590 + extra_width, 368 + extra_height);
}
