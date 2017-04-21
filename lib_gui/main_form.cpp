#include "main_form.h"
#include "ui_main_form.h"

MainForm::MainForm(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainForm) {
  ui->setupUi(this);

  SetWidgetProperties();
}

MainForm::~MainForm() { delete ui; }

void MainForm::SetWidgetProperties() {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setFixedSize(600, 400);
}
