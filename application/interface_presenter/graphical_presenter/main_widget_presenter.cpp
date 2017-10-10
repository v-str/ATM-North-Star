#include <main_widget_presenter.h>

#include <atm_main_widget.h>
#include <graphical_login_menu.h>
#include <graphical_registration_menu.h>

MainWidgetPresenter::MainWidgetPresenter(QObject* parent)
    : QObject(parent), atm_main_widget_(new AtmMainWidget) {}

MainWidgetPresenter::~MainWidgetPresenter() {
  delete atm_main_widget_;
  //  delete login_menu_;
  //  delete registration_menu_;
}

void MainWidgetPresenter::ShowMainWidget() {
  if (is_maximized_) {
    atm_main_widget_->showMaximized();
  } else {
    atm_main_widget_->setGeometry(
        main_widget_position_.x(), main_widget_position_.y(),
        main_widget_position_.width(), main_widget_position_.height());
    atm_main_widget_->showNormal();
  }
}

void MainWidgetPresenter::SetWidgetGeometry(const QRect& initial_position) {
  main_widget_position_ = initial_position;
}

void MainWidgetPresenter::SetMaximized(bool is_maximized) {
  is_maximized_ = is_maximized;
}
