#include <main_widget.h>

#include <atm_main_widget.h>

gui::MainWidget::MainWidget(QObject* parent)
    : QObject(parent), main_widget_(new AtmMainWidget) {}

gui::MainWidget::~MainWidget() { delete main_widget_; }

void gui::MainWidget::ShowMainWidget() { main_widget_->show(); }
