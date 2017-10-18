#include <exit_dialog.h>
#include <ui_exit_dialog.h>

#include <QApplication>
#include <QCursor>
#include <QList>
#include <QPixmap>
#include <QString>

#include <exit_dialog_geometry.h>
#include <initial_property_installer.h>
#include <place_arranger.h>
#include <widget_font.h>

ExitDialog::ExitDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::ExitDialog) {
  ui->setupUi(this);
  setWindowTitle("Exit window");

  SetExitDialogAppearance();
  SetBackgroundColor();

  SetInitialProperties();
  PaintWidgets();
  SetConnections();
}

ExitDialog::~ExitDialog() { delete ui; }

void ExitDialog::SetExitDialogAppearance() {
  PaintWidgets();
  SetFontStyle();
}

void ExitDialog::SetBackgroundColor() { color_designer_.SetBackground(this); }

void ExitDialog::ShowWidgetOnCenterAt(const QRect& widget_geometry) {
  PlaceArranger::PlaceToCenterRelativelyOf(this, widget_geometry);
  show();
}

void ExitDialog::SetConnections() {
  connect(ui->button_yes, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(ui->button_no, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitDialog::SetInitialProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kWidgetWidth, kWidgetHeight, InitialPropertyInstaller::kFixedSize);

  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
}

void ExitDialog::PaintWidgets() {
  QList<QLabel*> label_list = {ui->message_screen};
  QList<QPushButton*> button_list = {ui->button_yes, ui->button_no};
  QList<QFrame*> frame_list = {ui->frame};

  color_designer_.PaintWidgetSet(&label_list);
  color_designer_.PaintWidgetSet(&button_list);
  color_designer_.PaintWidgetSet(&frame_list);
}

void ExitDialog::SetFontStyle() {
  ui->message_screen->setFont(WidgetFont::SetFont(19));
  ui->button_no->setFont(WidgetFont::SetFont(14));
  ui->button_yes->setFont(WidgetFont::SetFont(14));
}
