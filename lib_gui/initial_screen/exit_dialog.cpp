#include "exit_dialog.h"
#include "ui_exit_dialog.h"

#include <QApplication>
#include <QPoint>
#include <QString>

#include <initial_property_installer.h>
#include <painter.h>
#include <widget_centerer.h>

ExitDialog::ExitDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::ExitDialog) {
  ui->setupUi(this);
  setWindowTitle("Exit");
  SetInitialProperties();
  SetConnections();
}

ExitDialog::~ExitDialog() { delete ui; }

void ExitDialog::SetWidgetColor(const QString& main_color,
                                const QString& secondary_color,
                                const QString& additional_color) {
  Painter::ChangeLabelColor(ui->message_screen, main_color);
  Painter::ChangeButtonColor(ui->button_no, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->button_yes, main_color, secondary_color,
                             additional_color);
}

void ExitDialog::SetBackgroundImage(const QString& background_image) {
  Painter::ChangeBackgroundImage(this, background_image);
}

void ExitDialog::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
}

void ExitDialog::ShowWidgetOnCenterAt(const QRect& widget_geometry) {
  WidgetCenterer::MoveToCenterRelativelyOf(this, widget_geometry);
  show();
}

void ExitDialog::SetConnections() {
  connect(ui->button_yes, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(ui->button_no, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitDialog::SetInitialProperties() {
  InitialPropertyInstaller::SetInitialProperties(this, 300, 150);
}
