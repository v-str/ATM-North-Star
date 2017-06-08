#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QPaintEvent>
#include <QVector>

#include <button_color_designer.h>
#include <initial_property_installer.h>
#include <painter.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  setMinimumSize(600, 400);
  SetWidgetAppearance();
  InitialPropertyInstaller::SetInitialProperties(this, 600, 400);
}

AtmMainWidget::~AtmMainWidget() { delete ui; }

void AtmMainWidget::SetWidgetAppearance(const QString& main_color,
                                        const QString& secondary_color,
                                        const QString& additional_color) {
  ColorizeButtons(main_color, secondary_color, additional_color);
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

void AtmMainWidget::ColorizeButtons(const QString& main_color,
                                    const QString& secondary_color,
                                    const QString& additional_color) {
  QList<QWidget*> color_list = {ui->exit_button,         ui->minimize_button,
                                ui->maximize_button,     ui->demo_mode_button,
                                ui->registration_button, ui->login_button};

  ButtonColorDesigner* button_designer = new ButtonColorDesigner(color_list);
  button_designer->SetWidgetPalette(main_color, secondary_color,
                                    additional_color);
  button_designer->PaintWidgets();
  delete button_designer;
}
