#include <main_widget.h>

#include <QRect>

#include <atm_main_widget.h>

gui::MainWidget::MainWidget(QObject* parent)
    : QObject(parent),
      main_widget_(new AtmMainWidget),
      main_widget_position_(new QRect) {
  SetMainWidgetAppearance();
}

gui::MainWidget::~MainWidget() {
  delete main_widget_;
  delete main_widget_position_;
}

void gui::MainWidget::SetMainWidgetAppearance() {
  main_widget_->SetWidgetAppearance("#00FFFF", "#001933", "#006666");
  main_widget_->SetBackgroundColor("black");
}

void gui::MainWidget::ShowMainWidget() {
  main_widget_->setGeometry(
      main_widget_position_->x(), main_widget_position_->y(),
      main_widget_position_->width(), main_widget_position_->height());
  main_widget_->show();
}

void gui::MainWidget::SetWidgetGeometry(const QRect& initial_position) {
  *main_widget_position_ = initial_position;
}
