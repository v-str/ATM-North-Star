#include "atm_splash_screen.h"
#include "ui_atm_splash_screen.h"

#include <memory>

#include <QApplication>
#include <QCoreApplication>

#include <close_block_filter.h>
#include <exit_widget.h>
#include <initial_property_installer.h>
#include <painter.h>
#include <text_color_swapper.h>
#include <timedate_changer.h>

AtmSplashScreen::AtmSplashScreen(QWidget* parent)
    : QMainWindow(parent),
      ui(new Ui::AtmSplashScreen),
      blink_color_one_("black"),
      blink_color_two_("grey") {
  ui->setupUi(this);

  InitializeObjects();
  SetWidgetAppearance(600, 400);
  BlockKeys();
  InitialSettings();
  SetConnections();
  RunTimers();
}

AtmSplashScreen::~AtmSplashScreen() {
  delete ui;
  delete color_swap_timer_;
  delete color_swapper_;
  delete time_date_timer_;
}

void AtmSplashScreen::SetCompanyName(const QString& atm_company_name) {
  ui->atm_company_name_label->setText(atm_company_name);
}

void AtmSplashScreen::SetTextColor(const QString& main_color,
                                   const QString additional_color) {
  Painter::ChangeLabelColor(ui->atm_company_name_label, main_color);
  Painter::ChangeLabelColor(ui->text_label, main_color);
  Painter::ChangeLabelColor(ui->timedate_label, main_color);
  Painter::ChangeLabelColor(ui->version_label, main_color);
  Painter::ChangeButtonColor(ui->exit_button, main_color, additional_color);
  Painter::ChangeFrameColor(ui->frame, main_color);
}

void AtmSplashScreen::SetAtmBlinkColor(const QString& color_one,
                                       const QString& color_two) {
  blink_color_one_ = color_one;
  blink_color_two_ = color_two;
  emit BlinkColor();
}

void AtmSplashScreen::SetBackgroundImage(const QString& background_image) {
  Painter::ChangeBackgroundImage(this, background_image);
}

void AtmSplashScreen::SetBackgroundColor(const QString& background_color) {
  Painter::ChangeBackgroundColor(this, background_color);
}

void AtmSplashScreen::AtmBlinkColor() {
  color_swapper_->ChangeColor(ui->atm_label, blink_color_one_,
                              blink_color_two_);
}

void AtmSplashScreen::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void AtmSplashScreen::ShowExitWidget() {
  ExitWidget* exit_widget = new ExitWidget(this);
  exit_widget->show();
}

void AtmSplashScreen::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Escape:
      emit ExitConfirmation();
    case Qt::Key_Space:
      event->ignore();
      break;
    default:
      break;
  }
  QWidget::keyPressEvent(event);
}

void AtmSplashScreen::InitialSettings() {
  SetCompanyName();
  SetTextColor();
  SetAtmBlinkColor();
  SetBackgroundImage();
}

void AtmSplashScreen::SetWidgetAppearance(int width, int height) {
  InitialPropertyInstaller::InstallInitialProperies(this, width, height);
}

void AtmSplashScreen::SetConnections() {
  connect(this, SIGNAL(BlinkColor()), SLOT(AtmBlinkColor()));
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(AtmBlinkColor()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
  connect(this, SIGNAL(ExitConfirmation()), SLOT(ShowExitWidget()));
}

void AtmSplashScreen::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  color_swapper_ = new TextColorSwapper();
  time_date_timer_ = new QTimer(ui->timedate_label);
}

void AtmSplashScreen::RunTimers() {
  color_swap_timer_->start(350);
  time_date_timer_->start(1000);
}

void AtmSplashScreen::BlockKeys() {
  ui->exit_button->installEventFilter(new CloseBlockFilter(ui->exit_button));
}
