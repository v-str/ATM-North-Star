#include <atm_main_widget.h>
#include <ui_atm_main_widget.h>

#include <QCursor>
#include <QLabel>
#include <QList>
#include <QPaintEvent>
#include <QPixmap>
#include <QResizeEvent>
#include <QTimer>

#include <initial_property_installer.h>
#include <painter.h>
#include <size_screen_controller.h>
#include <timedate_changer.h>
#include <widget_color.h>

AtmMainWidget::AtmMainWidget(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::AtmMainWidget) {
  ui->setupUi(this);
  setWindowTitle("ATM");
  SetInitialSettings();
  PaintWidgets();
  RunTimers();
  SetConnections();
}

AtmMainWidget::~AtmMainWidget() {
  delete ui;
  delete timedate_timer_;
}

void AtmMainWidget::SetWidgetAppearance(const QString& main_color,
                                        const QString& secondary_color,
                                        const QString& additional_color) {
  color_designer_.ConfigureWidgetColorSet(
      WidgetColor(main_color, secondary_color, additional_color));
  PaintWidgets();
}

void AtmMainWidget::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
}

void AtmMainWidget::TimeDateTick() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void AtmMainWidget::ResizeMainWidget() {
  if (!SizeScreenController::IsFullScreen()) {
    SizeScreenController::SetFullScreen(this);
  } else {
    SizeScreenController::SetNormalScreen(this);
  }
}

void AtmMainWidget::resizeEvent(QResizeEvent*) { SetFrameLayout(); }

void AtmMainWidget::SetConnections() {
  connect(timedate_timer_, SIGNAL(timeout()), SLOT(TimeDateTick()));
  connect(ui->maximize_button, SIGNAL(clicked(bool)), SLOT(ResizeMainWidget()));
}

void AtmMainWidget::SetInitialSettings() {
  QCursor custom_cursor(QPixmap(":/images/app_cursor.png"));
  setCursor(custom_cursor);

  InitializeObject();
  SetWidgetAppearance();
}

void AtmMainWidget::SetWidgetAppearance() {
  setMinimumSize(600, 400);
  InitialPropertyInstaller::SetInitialProperties(
      this, 600, 400, InitialPropertyInstaller::kResize);
}

void AtmMainWidget::SetFrameLayout() {
  int extra_width = width() - minimumWidth();
  int extra_height = height() - minimumHeight();
  ui->main_fraim->setGeometry(5, 5, 590 + extra_width, 390 + extra_height);
  ui->secondary_frame->setGeometry(5, 30, 580 + extra_width,
                                   332 + extra_height);
}

void AtmMainWidget::PaintWidgets() {
  QList<QFrame*> frame_list = {ui->main_fraim, ui->secondary_frame};
  QList<QPushButton*> button_list = {
      ui->exit_button,      ui->minimize_button,     ui->maximize_button,
      ui->demo_mode_button, ui->registration_button, ui->login_button};
  QList<QLabel*> label_list = {ui->timedate_label};

  color_designer_.PaintWidgetSet(frame_list);
  color_designer_.PaintWidgetSet(button_list);
  color_designer_.PaintWidgetSet(label_list);
}

void AtmMainWidget::InitializeObject() {
  timedate_timer_ = new QTimer(ui->timedate_label);
}

void AtmMainWidget::RunTimers() { timedate_timer_->start(1000); }
