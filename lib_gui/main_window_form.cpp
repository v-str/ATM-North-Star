#include "main_window_form.h"
#include "ui_main_window_form.h"

MainWindowForm::MainWindowForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowForm)
{
    ui->setupUi(this);
}

MainWindowForm::~MainWindowForm()
{
    delete ui;
}
