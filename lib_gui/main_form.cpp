#include "main_form.h"
#include "ui_main_form.h"

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
  delete color_timer_;
  delete running_text_timer_;
  delete running_text_;
}

void MainForm::ChangeColor() {
  if (is_state_changed_) {
    ChangeTextColor(ui->atm_label, "rgb(138, 226, 52)", false);
  } else {
    ChangeTextColor(ui->atm_label, "rgb(32, 74, 135)", true);
  }
}

void MainForm::RunText() { running_text_->UpdateText(ui->running_label); }

void MainForm::SetMainFormProperties() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
}

void MainForm::SetConnections() {
  connect(color_timer_, SIGNAL(timeout()), SLOT(ChangeColor()));
  connect(running_text_timer_, SIGNAL(timeout()), SLOT(RunText()));
}

void MainForm::ChangeTextColor(QWidget* widget,
                               const QString& text_color,
                               bool state) {
  QString stylesheet = QString(
                           "color: %1;"
                           "border: 0px solid black;")
                           .arg(text_color);

  widget->setStyleSheet(stylesheet);
  is_state_changed_ = state;
}

void MainForm::InitializeObjects() {
  color_timer_ = new QTimer(ui->atm_label);
  running_text_timer_ = new QTimer(ui->running_label);
  running_text_ = new RunningText();
}

void MainForm::RunTimers() {
  color_timer_->start(250);
  running_text_timer_->start(15);
}
