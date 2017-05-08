#include <exit_widget.h>
#include <ui_exit_widget.h>

#include <QApplication>

#include <initial_property_installer.h>

ExitWidget::ExitWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ExitWidget) {
  ui->setupUi(this);
  SetInitialProperties();
  SetConnections();
}

ExitWidget::~ExitWidget() { delete ui; }

void ExitWidget::SetConnections() {
  connect(ui->button_yes, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(ui->button_no, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitWidget::SetInitialProperties() {
  InitialPropertyInstaller::InstallInitialProperies(this, 300, 150);
}
