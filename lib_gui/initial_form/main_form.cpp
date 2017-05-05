#include "main_form.h"
#include "ui_main_form.h"

#include <QApplication>
#include <QCoreApplication>

#include "timedate_changer.h"
#include "widget_centerer.h"

MainForm::MainForm(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainForm) {
  ui->setupUi(this);

  InitializeObjects();
  SetMainFormProperties();
  SetConnections();
  RunTimers();
}

MainForm::~MainForm() {
  delete ui;
  delete color_swap_timer_;
  delete color_swapper_;
  delete time_date_timer_;
}

void MainForm::ChangeTextColor() {
  color_swapper_->ChangeColor(ui->atm_label, "rgb(114, 159, 207)",
                              "rgb(32, 74, 135)");
}

void MainForm::ChangeTimeDate() {
  TimeDateChanger::ChangeTimeData(ui->timedate_label);
}

void MainForm::keyPressEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Escape) {
    this->close();
  }
}

void MainForm::SetMainFormProperties() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
  WidgetCenterer::MoveToCenter(this);
}

void MainForm::SetConnections() {
  connect(color_swap_timer_, SIGNAL(timeout()), SLOT(ChangeTextColor()));
  connect(time_date_timer_, SIGNAL(timeout()), SLOT(ChangeTimeDate()));
}

void MainForm::InitializeObjects() {
  color_swap_timer_ = new QTimer(ui->atm_label);
  color_swapper_ = new TextColorSwapper();
  time_date_timer_ = new QTimer(ui->timedate_label);
}

void MainForm::RunTimers() {
  color_swap_timer_->start(350);
  time_date_timer_->start(1000);
}
