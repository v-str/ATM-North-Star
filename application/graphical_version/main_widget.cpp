#include <main_widget.h>

#include <QRect>

#include <atm_main_widget.h>

gui::MainWidget::MainWidget(QObject* parent)
    : QObject(parent),
      main_widget_(new AtmMainWidget),
      initial_main_widget_position_(new QRect) {
  SetMainWidgetAppearance();
}

gui::MainWidget::~MainWidget() {
  delete main_widget_;
  delete initial_main_widget_position_;
}

void gui::MainWidget::SetMainWidgetAppearance() {
  main_widget_->SetWidgetAppearance("#00FFFF", "#001933", "#009999");
  main_widget_->SetBackgroundColor("black");
}

void gui::MainWidget::ShowMainWidget() {
  main_widget_->setGeometry(initial_main_widget_position_->x(),
                            initial_main_widget_position_->y(),
                            initial_main_widget_position_->width(),
                            initial_main_widget_position_->height());
  main_widget_->show();
}

void gui::MainWidget::SetInitialPosition(const QRect& initial_position) {
  *initial_main_widget_position_ = initial_position;
}
