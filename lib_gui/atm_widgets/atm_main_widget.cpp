#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QList>
#include <QPaintEvent>

#include <initial_property_installer.h>
#include <painter.h>
#include <widget_color.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  SetUpWidgetProperties();
  PaintWidgets();
}

AtmMainWidget::~AtmMainWidget() { delete ui; }

void AtmMainWidget::SetWidgetAppearance(const QString& main_color,
                                        const QString& secondary_color,
                                        const QString& additional_color) {
  color_designer_.CustomizeColorSet(
      WidgetColor(main_color, secondary_color, additional_color));
  PaintWidgets();
}

void AtmMainWidget::resizeEvent(QResizeEvent*) { SetFrameLayout(); }

void AtmMainWidget::SetUpWidgetProperties() {
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
}

void AtmMainWidget::SetFrameLayout() {
  int extra_width = width() - minimumWidth();
  int extra_height = height() - minimumHeight();
  ui->main_fraim->setGeometry(5, 5, 590 + extra_width, 368 + extra_height);
  ui->secondary_frame->setGeometry(5, 30, 580 + extra_width,
                                   332 + extra_height);
}

void AtmMainWidget::PaintWidgets() {
  QList<QFrame*> frame_list = {ui->main_fraim, ui->secondary_frame};
  QList<QPushButton*> button_list = {
      ui->exit_button,      ui->minimize_button,     ui->maximize_button,
      ui->demo_mode_button, ui->registration_button, ui->login_button};

  color_designer_.PaintWidgetSet(frame_list);
  color_designer_.PaintWidgetSet(button_list);
}
