#include <v_group_composer.h>

#include <QWidget>

void VGroupComposer::SetInitialGroupGeometry(
    const QVector<QRect>& widget_vector) {
  geometry_vector_ = widget_vector;
}

void VGroupComposer::ScaleVGroup(QVector<QWidget*> scale_vector) {
  ComputeHeadGroupGeometry(scale_vector[0]);

  for (int element = 1; element < scale_vector.size(); ++element) {
    ComputeElementGeometry(scale_vector[element - 1]);
    scale_vector[element]->setGeometry(geometry_);
  }
}

void VGroupComposer::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}

void VGroupComposer::ComputeElementGeometry(QWidget* previous_widget) {
  geometry_.setX(previous_widget->x());
  geometry_.setY(previous_widget->y() + previous_widget->height() +
                 widget_interval_);

  geometry_.setWidth(previous_widget->width());
  geometry_.setHeight(previous_widget->height());
}

void VGroupComposer::ComputeHeadGroupGeometry(QWidget* widget) {
  ComposeGeometry(geometry_vector_[0], widget);
}
