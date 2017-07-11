#include <v_group_composer.h>

#include <QWidget>

void VGroupComposer::SetInitialGroupGeometry(
    const QVector<QRect>& widget_vector) {
  geometry_vector_ = widget_vector;
}

void VGroupComposer::ScaleVGroup(QVector<QWidget*> scale_vector) {
  ComputeHeadGroupGeometry(scale_vector[0]);

  for (int element = 1; element < scale_vector.size(); ++element) {
    ComputeElementGeometry(scale_vector[element - 1],
                           geometry_vector_[element]);
    scale_vector[element]->setGeometry(geometry_);
  }
}

void VGroupComposer::SetWidgetInterval(int widget_interval) {
  widget_interval_ = widget_interval;
}

void VGroupComposer::ComputeElementGeometry(
    QWidget* previous_widget, const QRect& current_widget_geometry) {
  geometry_.setX(previous_widget->x());
  geometry_.setY(previous_widget->y() + previous_widget->height() +
                 widget_interval_);

  geometry_.setWidth(current_widget_geometry.width() +
                     (GetDeltaSize().Width() * StretchFactor().XAxisFactor()));
  geometry_.setHeight(
      current_widget_geometry.height() +
      (GetDeltaSize().Height() * StretchFactor().YAxisFactor()));
}

void VGroupComposer::ComputeHeadGroupGeometry(QWidget* widget) {
  ComposeGeometry(geometry_vector_[0], widget);
}
