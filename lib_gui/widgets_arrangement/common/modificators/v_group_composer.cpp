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
  QRect geometry;
  geometry.setX(geometry_vector_[0].x());
  geometry.setY(geometry_vector_[0].y());
  geometry.setWidth(geometry_vector_[0].width() + delta_size_.Width() * 0.1);
  geometry.setHeight(geometry_vector_[0].height() + delta_size_.Height() * 0.1);
  scale_vector[0]->setGeometry(geometry);

  for (int i = 1; i < scale_vector.size(); ++i) {
    geometry.setX(scale_vector[i]->x());
    geometry.setY(scale_vector[i - 1]->y() + scale_vector[i - 1]->height() +
                  10);
    geometry.setWidth(geometry_vector_[i].width() + delta_size_.Width() * 0.1);
    geometry.setHeight(geometry_vector_[i].height() +
                       delta_size_.Height() * 0.1);
    scale_vector[i]->setGeometry(geometry);
  }
}
