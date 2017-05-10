#include <exit_widget.h>
#include <ui_exit_widget.h>

#include <QApplication>
#include <QString>

#include <initial_property_installer.h>
#include <painter.h>

ExitWidget::ExitWidget(QWidget* parent)
    : QWidget(parent), ui(new Ui::ExitWidget) {
  ui->setupUi(this);
  SetInitialProperties();
  SetConnections();
}

ExitWidget::~ExitWidget() { delete ui; }

void ExitWidget::SetWidgetColor(const QString& main_color,
                                const QString& secondary_color,
                                const QString& additional_color) {
  Painter::ChangeLabelColor(ui->message_screen, main_color);
  Painter::ChangeButtonColor(ui->button_no, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->button_yes, main_color, secondary_color,
                             additional_color);
}

void ExitWidget::SetConnections() {
  connect(ui->button_yes, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(ui->button_no, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitWidget::Show() {
  SetInitialProperties();
  show();
}

void ExitWidget::SetInitialProperties() {
  InitialPropertyInstaller::SetInitialProperties(this, 300, 180);
}
