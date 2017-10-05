#include <main_widget_presenter.h>

#include <QRect>

#include <atm_main_widget.h>

MainWidgetPresenter::MainWidgetPresenter(QObject* parent)
    : QObject(parent),
      atm_main_widget_(new AtmMainWidget),
      main_widget_position_(new QRect) {}

MainWidgetPresenter::~MainWidgetPresenter() {
  delete atm_main_widget_;
  delete main_widget_position_;
}

void MainWidgetPresenter::ShowMainWidget() {
  atm_main_widget_->setGeometry(
      main_widget_position_->x(), main_widget_position_->y(),
      main_widget_position_->width(), main_widget_position_->height());
  atm_main_widget_->showNormal();
}

void MainWidgetPresenter::SetWidgetGeometry(const QRect& initial_position) {
  *main_widget_position_ = initial_position;
}
