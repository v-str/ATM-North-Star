#include "main_form.h"
#include "ui_main_form.h"

MainForm::MainForm(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainForm) {
  ui->setupUi(this);

  timer_ = new QTimer(ui->atm_label);

  SetWidgetProperties();
  SetConnections();

  timer_->start(250);
}

MainForm::~MainForm() {
  delete ui;
  delete timer_;
}

void MainForm::ChangeColor() {
  if (is_state_changed_) {
    ChangeTextColor(ui->atm_label, "rgb(138, 226, 52)", false);
  } else {
    ChangeTextColor(ui->atm_label, "rgb(32, 74, 135)", true);
  }
}

void MainForm::SetWidgetProperties() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
}

void MainForm::SetConnections() {
  connect(timer_, SIGNAL(timeout()), SLOT(ChangeColor()));
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
