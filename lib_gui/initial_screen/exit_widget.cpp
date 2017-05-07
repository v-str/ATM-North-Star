#include <exit_widget.h>
#include <ui_exit_widget.h>

#include <QTimer>

#include <initial_property_installer.h>

ExitWidget::ExitWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ExitWidget) {
  ui->setupUi(this);
}

ExitWidget::~ExitWidget() {
  delete ui;
  delete timer_;
}

void ExitWidget::SetInitialProperties() {
  InitialPropertyInstaller::InstallInitialProperies(this, 300, 150);
}
