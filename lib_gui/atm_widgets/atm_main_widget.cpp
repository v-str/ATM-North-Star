#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QPaintEvent>

#include <initial_property_installer.h>
#include <painter.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
}

AtmMainWidget::~AtmMainWidget() { delete ui; }

void AtmMainWidget::SetAppearance(const QString& main_color,
                                  const QString& secondary_color,
                                  const QString& additional_color) {
  Painter::ChangeButtonColor(ui->exit_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->minimize_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->maximize_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->demo_mode_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeButtonColor(ui->registration_button, main_color,
                             secondary_color, additional_color);
  Painter::ChangeButtonColor(ui->login_button, main_color, secondary_color,
                             additional_color);
  Painter::ChangeFrameColor(ui->main_fraim, main_color);
}

void AtmMainWidget::resizeEvent(QResizeEvent*) { SetFrameLayout(); }

void AtmMainWidget::SetFrameLayout() {
  int extra_width = width() - minimumWidth();
  int extra_height = height() - minimumHeight();
  ui->main_fraim->setGeometry(5, 5, 590 + extra_width, 368 + extra_height);
  ui->secondary_frame->setGeometry(5, 30, 580 + extra_width,
                                   332 + extra_height);
}
