#include <exit_dialog.h>

#include <QApplication>
#include <QCursor>
#include <QFrame>
#include <QLabel>
#include <QList>
#include <QPixmap>
#include <QString>

#include <atm_button.h>
#include <exit_dialog_geometry.h>
#include <initial_property_installer.h>
#include <place_arranger.h>
#include <widget_font.h>

ExitDialog::ExitDialog(QWidget* parent)
    : QDialog(parent),
      exit_dialog_frame_(new QFrame(this)),
      button_yes_(new AtmButton("Yes", exit_dialog_frame_)),
      button_no_(new AtmButton("No", exit_dialog_frame_)),
      screen_message_(new QLabel("Exit atm?", exit_dialog_frame_)) {
  setWindowTitle("Exit window");

  SetExitDialogAppearance();
  SetBackgroundColor();
  SetGeometry();

  SetInitialProperties();
  PaintWidgets();
  SetConnections();
}

ExitDialog::~ExitDialog() {}

void ExitDialog::SetExitDialogAppearance() {
  PaintWidgets();
  SetFontStyle();
}

void ExitDialog::SetBackgroundColor() { color_designer_.SetBackground(this); }

void ExitDialog::SetGeometry() {
  setGeometry(ExitDialogGeometry::ExitDialog());
  exit_dialog_frame_->setGeometry(ExitDialogGeometry::ExitDialogFrame());
  button_yes_->setGeometry(ExitDialogGeometry::ButtonYes());
  button_no_->setGeometry(ExitDialogGeometry::ButtonNo());
  screen_message_->setGeometry(ExitDialogGeometry::ScreenMessage());
}

void ExitDialog::ShowWidgetOnCenterAt(const QRect& widget_geometry) {
  PlaceArranger::PlaceToCenterRelativelyOf(this, widget_geometry);
  show();
}

void ExitDialog::SetConnections() {
  connect(button_yes_, SIGNAL(clicked(bool)), qApp, SLOT(closeAllWindows()));
  connect(button_no_, SIGNAL(clicked(bool)), SLOT(close()));
}

void ExitDialog::SetInitialProperties() {
  InitialPropertyInstaller::SetInitialProperties(
      this, kWidgetWidth, kWidgetHeight, InitialPropertyInstaller::kFixedSize);

  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);
}

void ExitDialog::PaintWidgets() {
  QList<QLabel*> label_list = {screen_message_};
  QList<QPushButton*> button_list = {button_yes_, button_no_};
  QList<QFrame*> frame_list = {exit_dialog_frame_};

  color_designer_.PaintWidgetSet(&label_list);
  color_designer_.PaintWidgetSet(&button_list);
  color_designer_.PaintWidgetSet(&frame_list);
}

void ExitDialog::SetFontStyle() {
  screen_message_->setFont(WidgetFont::SetFont(19));
  screen_message_->setAlignment(Qt::AlignCenter);
  button_yes_->SetFont(WidgetFont::SetFont(14));
  button_no_->SetFont(WidgetFont::SetFont(14));
}
