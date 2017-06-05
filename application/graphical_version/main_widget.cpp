#include <main_widget.h>

#include <atm_main_widget.h>

MainWidget::MainWidget(QObject* parent)
    : QObject(parent), main_widget_(new AtmMainWidget) {}

MainWidget::~MainWidget() { delete main_widget_; }

void MainWidget::ShowMainWidget() { main_widget_->show(); }
