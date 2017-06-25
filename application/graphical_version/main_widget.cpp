#include <main_widget.h>

#include <QRect>

#include <atm_main_widget.h>

gui::MainWidget::MainWidget(QObject* parent)
    : QObject(parent),
      atm_main_widget_(new AtmMainWidget),
      main_widget_position_(new QRect) {
  SetMainWidgetAppearance();
}

gui::MainWidget::~MainWidget() {
  delete atm_main_widget_;
  delete main_widget_position_;
}

void gui::MainWidget::SetMainWidgetAppearance() {
  atm_main_widget_->SetWidgetAppearance();
  atm_main_widget_->SetBackgroundColor("black");
}

void gui::MainWidget::ShowMainWidget() {
  if (is_full_screen_) {
    atm_main_widget_->showFullScreen();

  } else {
    atm_main_widget_->setGeometry(
        main_widget_position_->x(), main_widget_position_->y(),
        main_widget_position_->width(), main_widget_position_->height());
    atm_main_widget_->showNormal();
  }
}

void gui::MainWidget::SetWidgetGeometry(const QRect& initial_position) {
  *main_widget_position_ = initial_position;
}

void gui::MainWidget::FullScreenSizeCondition(bool screen_condition) {
  is_full_screen_ = screen_condition;
}
