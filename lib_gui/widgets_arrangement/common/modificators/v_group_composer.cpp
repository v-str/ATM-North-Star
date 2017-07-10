#include <v_group_composer.h>

#include <QWidget>

void VGroupComposer::SetDeltaSize(const DeltaSize& delta_size) {
  delta_size_ = delta_size;
}

void VGroupComposer::SetInitialGroupGeometry(
    const QVector<QRect>& widget_vector) {
  geometry_vector_ = widget_vector;
}

void VGroupComposer::ScaleVGroup(QVector<QWidget*> scale_vector) {
  ComputeHeadGroupGeometry(scale_vector[0]);

  for (int element = 1; element < scale_vector.size(); ++element) {
    ComputeElementPosition(scale_vector[element], scale_vector[element - 1]);
    ComputeElementSize(element);
    scale_vector[element]->setGeometry(geometry_);
  }
}

void VGroupComposer::SetSpace(int widget_interval) {
  widget_interval_ = widget_interval;
}

void VGroupComposer::ComputeElementPosition(QWidget* current_widget,
                                            QWidget* previous_widget) {
  geometry_.setX(current_widget->x());
  geometry_.setY(previous_widget->y() + previous_widget->height() +
                 widget_interval_);
}

void VGroupComposer::ComputeElementSize(int element_number) {
  geometry_.setWidth(geometry_vector_[element_number].width() +
                     delta_size_.Width() * 0.1);
  geometry_.setHeight(geometry_vector_[element_number].height() +
                      delta_size_.Height() * 0.1);
}

void VGroupComposer::ComputeHeadGroupGeometry(QWidget* widget) {
  geometry_.setX(geometry_vector_[0].x());
  geometry_.setY(geometry_vector_[0].y());

  ComputeElementSize(0);

  widget->setGeometry(geometry_);
}
